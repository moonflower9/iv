# iv

`iv` is a C-based application built with [SDL2](https://libsdl.org/).  
This release provides compiled binaries for **Windows** and **Linux**.

---

## 📦 Downloads

Visit the [Releases](https://github.com/moonflower9/iv/releases) tab to download the appropriate archive for your system:

- **Windows (x86_64)** → `iv-v1.0.0-windows-x86_64.zip`
- **Linux (x86_64)** → `iv-v1.0.0-linux-x86_64.tar.gz`

---

## 💻 Installation & Running

### **Windows**
**Included files:**
```
iv.exe       # Executable binary
SDL2.dll     # SDL2 runtime library
README.txt   # Quick start instructions
LICENSE.txt  # Project license
```

**Steps:**
1. **Download and extract** the archive:  
   Right-click → *Extract All...* in Explorer, or use a zip tool.
2. **Open the extracted folder** in File Explorer.
3. Run the program:  
   - In PowerShell / Command Prompt:
     ```powershell
     cd path\to\iv-v1.0.0
     .\iv.exe <image>
     ```
     Replace `<image>` with the path to an image file you want to load.
4. The `SDL2.dll` file **must remain in the same folder** as `iv.exe`.

> ⚠ **Note:** If Windows warns that the file is from the internet:  
> Right-click `iv.exe` → **Properties** → Check *Unblock* → Click **OK**.

---

### **Linux**

The Linux binary is dynamically linked against SDL2, so you must have SDL2 installed.

#### Dependencies
On **Debian / Ubuntu / Mint**:
```bash
sudo apt update
sudo apt install libsdl2-2.0-0
```
On **Fedora / RHEL**:
```bash
sudo dnf install SDL2
```
On **Arch Linux**:
```bash
sudo pacman -S sdl2
```

#### Run Program
1. Download and extract:
   ```bash
   tar -xzf iv-v1.0.0-linux-x86_64.tar.gz
   cd iv-v1.0.0
   ```
2. Make sure the binary is executable:
   ```bash
   chmod +x iv
   ```
3. Execute:
   ```bash
   ./iv <image>
   ```
   Replace `<image>` with the path to an image file you want to load.

---

## 🛠 Development Builds

If you wish to compile from source:

```bash
git clone https://github.com/moonflower9/iv.git
cd iv
```

### Linux Build
```bash
gcc iv.c -lSDL2 -o iv
```

### Windows Build (cross-compile from WSL/Linux)
**Install MinGW-w64:**
```bash
sudo apt install mingw-w64
```

**Compile:**
```bash
x86_64-w64-mingw32-gcc iv.c -o iv.exe \
    -I./SDL2/include \
    -L./SDL2/lib \
    -lmingw32 -lSDL2main -lSDL2
```

Bundle `SDL2.dll` with `iv.exe` for distribution.
