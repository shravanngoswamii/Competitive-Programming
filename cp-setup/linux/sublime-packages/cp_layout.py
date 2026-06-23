import sublime
import sublime_plugin

CP_DIR        = "CP_DIR_PLACEHOLDER"
INPUT_FILE    = f"{CP_DIR}/input.txt"
EXPECTED_FILE = f"{CP_DIR}/expected.txt"
OUTPUT_FILE   = f"{CP_DIR}/output.txt"

class CpLayoutCommand(sublime_plugin.WindowCommand):
    def run(self):
        window = self.window
        current_view = window.active_view()

        window.run_command("set_layout", {
            "cols":  [0.0, 0.55, 1.0],
            "rows":  [0.0, 0.38, 0.62, 1.0],
            "cells": [
                [0, 0, 1, 3],   # left  — code (full height)
                [1, 0, 2, 1],   # right top    — input.txt
                [1, 1, 2, 2],   # right middle — expected.txt
                [1, 2, 2, 3],   # right bottom — output.txt
            ]
        })

        if current_view:
            window.set_view_index(current_view, 0, 0)

        window.set_view_index(window.open_file(INPUT_FILE),    1, 0)
        window.set_view_index(window.open_file(EXPECTED_FILE), 2, 0)
        window.set_view_index(window.open_file(OUTPUT_FILE),   3, 0)

        window.focus_view(current_view)
