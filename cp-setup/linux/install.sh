#!/bin/bash
set -e

DEFAULT_CP_DIR="$HOME/CP"
read -rp "CP directory [default: $DEFAULT_CP_DIR]: " CP_DIR
CP_DIR="${CP_DIR:-$DEFAULT_CP_DIR}"
SUBLIME_USER="$HOME/.config/sublime-text/Packages/User"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if ! command -v g++ &>/dev/null; then
    command -v dnf &>/dev/null && sudo dnf install -y gcc-c++
    command -v apt &>/dev/null && sudo apt install -y g++
fi

if ! command -v subl &>/dev/null; then
    if command -v dnf &>/dev/null; then
        sudo rpm -v --import https://download.sublimetext.com/sublimehq-rpm-pub.gpg
        sudo dnf config-manager --add-repo https://download.sublimetext.com/rpm/stable/x86_64/sublime-text.repo
        sudo dnf install -y sublime-text
    elif command -v apt &>/dev/null; then
        wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg | sudo apt-key add -
        sudo apt install -y apt-transport-https
        echo "deb https://download.sublimetext.com/ apt/stable/" | sudo tee /etc/apt/sources.list.d/sublime-text.list
        sudo apt update && sudo apt install -y sublime-text
    fi
fi

mkdir -p "$CP_DIR"
touch "$CP_DIR/input.txt" "$CP_DIR/expected.txt" "$CP_DIR/output.txt"
sed "s|CP_DIR_PLACEHOLDER|$CP_DIR|g" "$SCRIPT_DIR/cp-files/cpcheck.py" > "$CP_DIR/cpcheck.py"

mkdir -p "$SUBLIME_USER"
for file in "$SCRIPT_DIR/sublime-packages/"*; do
    fname="$(basename "$file")"
    if [[ "$fname" == *.py ]]; then
        sed "s|CP_DIR_PLACEHOLDER|$CP_DIR|g" "$file" > "$SUBLIME_USER/$fname"
    else
        cp "$file" "$SUBLIME_USER/$fname"
    fi
done

PREFS="$SUBLIME_USER/Preferences.sublime-settings"
if [ -f "$PREFS" ]; then
    grep -q "save_on_focus_lost" "$PREFS" || sed -i 's/^}$/\t"save_on_focus_lost": true,\n}/' "$PREFS"
else
    echo '{ "save_on_focus_lost": true }' > "$PREFS"
fi

echo "✓ Done — install Terminus in Sublime to finish setup"
