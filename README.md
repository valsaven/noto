# noto
A command line journal 🌈

<p align="left">
  <img width="600" src="https://cdn.jsdelivr.net/gh/valsaven/noto@cb2e8bae/noto.svg">
</p>

## Usage

```sh
### Make a new entry:
noto "Hello, noto!"
noto 123

### Show all entries:
noto
@a9b1ah Hello, noto!
@e7sa3b 123

### Show the entry:
noto @a9b1ah
Hello, noto!

### Remove an entry:
noto -r @a9b1ah
```

## Install from AUR (Arch Linux)

```sh
yay -S noto
```

## Build from source

### Prerequisites
- GCC ≥ 13
- Meson ≥ 1.9.1
- Ninja ≥ 1.13.2

### Build instructions

```sh
# Clone and enter the repo
git clone https://github.com/valsaven/noto.git
cd noto

# Configure and build (out-of-source build is mandatory)
meson setup build
meson compile -C build

# The binary will be at build/noto.exe (Windows) or build/noto (Linux/macOS)
```

### Optional: release build (smaller & faster)

```sh
meson setup -Dbuildtype=release build-release
meson compile -C build-release
```

### Run

```sh
./build/noto    # Linux/macOS
build\noto.exe  # Windows PowerShell
```

### Install (optional)

```sh
meson install -C build  # installs to /usr/local (Linux) or your prefix
```