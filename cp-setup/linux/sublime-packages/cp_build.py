import sublime
import sublime_plugin
import subprocess
import os
import threading

CP_DIR = "CP_DIR_PLACEHOLDER"

def run_build(view):
    file = view.file_name()
    if not file or not file.endswith('.cpp'):
        sublime.set_timeout(lambda: view.set_status('cp', 'CP: not a .cpp file'), 0)
        return

    file_path = os.path.dirname(file)
    exe       = os.path.join(file_path, os.path.splitext(os.path.basename(file))[0])

    sublime.set_timeout(lambda: view.set_status('cp', '⏳  compiling…'), 0)

    r = subprocess.run(
        ['g++', '-std=c++20', '-O2', '-include', 'bits/stdc++.h', file, '-o', exe],
        capture_output=True, text=True
    )
    if r.returncode != 0:
        err = r.stderr.strip().split('\n')[0]
        sublime.set_timeout(lambda: (
            view.set_status('cp', f'✗  Compile Error — {err}'),
            sublime.error_message(r.stderr)
        ), 0)
        return

    sublime.set_timeout(lambda: view.set_status('cp', '⏳  running…'), 0)

    try:
        with open(f"{CP_DIR}/input.txt") as inp, \
             open(f"{CP_DIR}/output.txt", 'w') as out:
            r2 = subprocess.run([exe], stdin=inp, stdout=out,
                                stderr=subprocess.PIPE, text=True, timeout=5)
    except subprocess.TimeoutExpired:
        sublime.set_timeout(lambda: view.set_status('cp', '✗  TLE  (>5s)'), 0)
        return

    if r2.returncode != 0:
        sublime.set_timeout(lambda: view.set_status('cp', '✗  Runtime Error'), 0)
        return

    r3 = subprocess.run(['python3', f"{CP_DIR}/cpcheck.py"],
                        capture_output=True, text=True)
    result = r3.stdout.strip().split('\n')[0]
    sublime.set_timeout(lambda: view.set_status('cp', result), 0)


class CpBuildCommand(sublime_plugin.WindowCommand):
    def run(self):
        view = self.window.active_view()
        if not view:
            return
        view.run_command('save')
        threading.Thread(target=run_build, args=(view,), daemon=True).start()
