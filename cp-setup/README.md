# CP Setup — Sublime Text (Linux)

## Install

```sh
cd linux && ./install.sh
```

Then install **Terminus** in Sublime: `Ctrl+Shift+P` -> `Package Control: Install Package` -> `Terminus`

## Keybindings

| Key | Action |
|---|---|
| `Ctrl+B` | Compile, run, compare (result in status bar) |
| `Ctrl+Shift+I` | CP layout: code / input / expected / output |
| `Ctrl+`` ` | Toggle terminal panel |
| `Ctrl+Shift+`` ` | New terminal session |
| `cp` + Tab | Insert CP template in a `.cpp` file |

## Workflow

1. Open `.cpp` file, press `Ctrl+Shift+I`
2. Paste sample input into `input.txt`, expected output into `expected.txt` (optional)
3. `Ctrl+B` shows `AC`, `WA`, `TLE`, or error in the status bar

## Writing blog posts

Install [cpscribe](https://github.com/shravanngoswamii/cpscribe), then:

```sh
cpscribe post https://codeforces.com/contest/1234/problem/A
cpscribe post A.cpp   # URL read from a comment in the file
```
