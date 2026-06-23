#!/bin/bash
set -e

# ── Config ────────────────────────────────────────────────────────────────────
DEFAULT_CP_DIR="$HOME/CP"
read -rp "CP directory path [default: $DEFAULT_CP_DIR]: " CP_DIR
CP_DIR="${CP_DIR:-$DEFAULT_CP_DIR}"

SUBLIME_USER="$HOME/.config/sublime-text/Packages/User"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo ""
echo "CP directory : $CP_DIR"
echo "Sublime User : $SUBLIME_USER"
echo ""

# ── 1. Install g++ ────────────────────────────────────────────────────────────
if ! command -v g++ &>/dev/null; then
    echo "→ Installing g++..."
    if command -v dnf &>/dev/null; then
        sudo dnf install -y gcc-c++
    elif command -v apt &>/dev/null; then
        sudo apt install -y g++
    else
        echo "  Could not detect package manager. Install g++ manually."
    fi
else
    echo "✓ g++ already installed"
fi

# ── 2. Install Sublime Text ───────────────────────────────────────────────────
if ! command -v subl &>/dev/null; then
    echo "→ Installing Sublime Text..."
    if command -v dnf &>/dev/null; then
        sudo rpm -v --import https://download.sublimetext.com/sublimehq-rpm-pub.gpg
        sudo dnf config-manager --add-repo https://download.sublimetext.com/rpm/stable/x86_64/sublime-text.repo
        sudo dnf install -y sublime-text
    elif command -v apt &>/dev/null; then
        wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg | sudo apt-key add -
        sudo apt install -y apt-transport-https
        echo "deb https://download.sublimetext.com/ apt/stable/" | sudo tee /etc/apt/sources.list.d/sublime-text.list
        sudo apt update && sudo apt install -y sublime-text
    else
        echo "  Could not detect package manager. Install Sublime Text manually from https://www.sublimetext.com"
    fi
else
    echo "✓ Sublime Text already installed"
fi

# ── 3. Create CP directory and files ─────────────────────────────────────────
echo "→ Setting up CP directory at $CP_DIR..."
mkdir -p "$CP_DIR"
touch "$CP_DIR/input.txt" "$CP_DIR/expected.txt" "$CP_DIR/output.txt"

sed "s|CP_DIR_PLACEHOLDER|$CP_DIR|g" "$SCRIPT_DIR/cp-files/cpcheck.py" > "$CP_DIR/cpcheck.py"
echo "✓ CP files ready"

# ── 4. Copy Sublime packages ──────────────────────────────────────────────────
echo "→ Copying Sublime packages..."
mkdir -p "$SUBLIME_USER"

for file in "$SCRIPT_DIR/sublime-packages/"*; do
    fname="$(basename "$file")"
    if [[ "$fname" == *.py ]]; then
        sed "s|CP_DIR_PLACEHOLDER|$CP_DIR|g" "$file" > "$SUBLIME_USER/$fname"
    else
        cp "$file" "$SUBLIME_USER/$fname"
    fi
done

# ── 5. Patch Preferences (add save_on_focus_lost if missing) ─────────────────
PREFS="$SUBLIME_USER/Preferences.sublime-settings"
if [ -f "$PREFS" ]; then
    if ! grep -q "save_on_focus_lost" "$PREFS"; then
        # Insert before the closing brace
        sed -i 's/^}$/\t"save_on_focus_lost": true,\n}/' "$PREFS"
        echo "✓ Patched save_on_focus_lost into Preferences"
    else
        echo "✓ save_on_focus_lost already set"
    fi
else
    echo '{ "save_on_focus_lost": true }' > "$PREFS"
    echo "✓ Created Preferences with save_on_focus_lost"
fi

# ── Done ──────────────────────────────────────────────────────────────────────
echo ""
echo "✓ Done! One manual step remaining:"
echo ""
echo "  Open Sublime Text and install the Terminus package:"
echo "    1. Ctrl+Shift+P → 'Install Package Control' → Enter"
echo "    2. Ctrl+Shift+P → 'Package Control: Install Package' → 'Terminus'"
echo ""
echo "Keybindings:"
echo "  Ctrl+B          → compile + run + compare"
echo "  Ctrl+Shift+I    → open CP layout (code | input | expected | output)"
echo "  Ctrl+\`          → toggle terminal panel"
echo "  Ctrl+Shift+\`    → open new terminal tab"
echo "  (type 'cp' + Tab in a .cpp file for the template)"
