# CP Setup — Sublime Text (Linux)

## Install

```bash
cd linux && ./install.sh
```

Then install **Terminus** in Sublime: `Ctrl+Shift+P` → `Package Control: Install Package` → `Terminus`

## Keybindings

| Key | Action |
|---|---|
| `Ctrl+B` | Compile → run → compare (result in status bar) |
| `Ctrl+Shift+I` | CP layout: code / input / expected / output |
| `Ctrl+`` ` | Toggle terminal panel |
| `Ctrl+Shift+`` ` | New terminal panel session |
| `cp` + Tab | Insert CP template in `.cpp` file |

## Workflow

1. Open `.cpp` file → `Ctrl+Shift+I` for layout
2. Paste sample input into `input.txt`, expected output into `expected.txt` (optional)
3. `Ctrl+B` → status bar shows `✓ AC`, `✗ WA`, `✗ TLE`, or `✗ Runtime/Compile Error`

## cfpost

Generate a blog post for a solved problem:

```bash
cfpost https://codeforces.com/contest/1234/problem/A
cfpost A.cpp          # URL extracted from comment in the file
cfpost A.cpp A.cpp    # explicit URL + solution file
```
