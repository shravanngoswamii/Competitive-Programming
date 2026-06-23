#!/usr/bin/env python3

CP_DIR = "CP_DIR_PLACEHOLDER"

def normalize(text):
    lines = [line.rstrip() for line in text.splitlines()]
    while lines and not lines[-1]:
        lines.pop()
    return lines

with open(f"{CP_DIR}/output.txt") as f:
    actual = normalize(f.read())

with open(f"{CP_DIR}/expected.txt") as f:
    raw = f.read().strip()

if not raw:
    print("✓  Done — " + (" | ".join(actual) if actual else "(no output)"))
else:
    expected = normalize(raw)
    if actual == expected:
        print("✓  AC  — output matches expected")
    else:
        n = max(len(actual), len(expected))
        diffs = []
        for i in range(n):
            a = actual[i]   if i < len(actual)   else "<missing>"
            e = expected[i] if i < len(expected) else "<missing>"
            if a != e:
                diffs.append(f"line {i+1}: got [{a}]  expected [{e}]")
        print("✗  WA  — " + diffs[0] if diffs else "✗  WA  — (line count mismatch)")
        for d in diffs[1:]:
            print("         " + d)
