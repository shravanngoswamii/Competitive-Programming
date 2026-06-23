# CP Setup — Sublime Text (Linux)

Competitive programming setup for Sublime Text on Linux.

## Install

```bash
cd linux
./install.sh
```

Then open Sublime Text and install **Terminus** (one-time manual step):
1. `Ctrl+Shift+P` → `Install Package Control` → Enter
2. `Ctrl+Shift+P` → `Package Control: Install Package` → `Terminus`

## What it sets up

| File | Purpose |
|---|---|
| `cp_build.py` | `Ctrl+B` — compiles, runs against `input.txt`, shows AC/WA in status bar |
| `cp_layout.py` | `Ctrl+Shift+I` — 4-panel layout: code / input / expected / output |
| `cpcheck.py` | Smart comparison: ignores trailing whitespace/newlines |
| `cp_template.sublime-snippet` | `cp` + Tab — inserts CP template in any `.cpp` file |
| `CP.sublime-build` | Fallback build system (bypassed for `.cpp` by `cp_build.py`) |
| `Default (Linux).sublime-keymap` | All keybindings |

## Keybindings

| Key | Action |
|---|---|
| `Ctrl+B` | Compile + run + compare (result in status bar) |
| `Ctrl+Shift+I` | Open CP layout |
| `Ctrl+`` ` | Toggle terminal panel |
| `Ctrl+Shift+`` ` | Open new terminal tab |
| `cp` + Tab | Insert CP template |

## Workflow

1. Open your `.cpp` file → press `Ctrl+Shift+I` for the layout
2. Paste sample input into `input.txt` (right-top panel)
3. Paste expected output into `expected.txt` (right-middle panel) — optional
4. Press `Ctrl+B` — status bar shows `✓ AC`, `✗ WA`, `✗ TLE`, or `✗ Runtime Error`

## CP Directory

The install script creates a `~/CP/` directory (configurable) with:
- `input.txt` — paste test input here
- `expected.txt` — paste expected output here (leave empty to skip comparison)
- `output.txt` — auto-written on every run
- `cpcheck.py` — comparison script

## Directory structure

```
cp-setup/
├── linux/
│   ├── sublime-packages/   ← copied to ~/.config/sublime-text/Packages/User/
│   ├── cp-files/           ← placed at ~/CP/
│   └── install.sh
├── windows/                ← old Windows setup (reference only)
└── README.md
```
