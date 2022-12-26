# noto
A command line journal 🌈

<p align="left">
  <img width="600" src="https://cdn.jsdelivr.net/gh/valsaven/noto@cb2e8bae/noto.svg">
</p>

### Install from AUR

```bash
yay -S noto
```

### Usage

```bash
### Add new entry:
noto "Hello, noto!"
noto 123

### Show all entries:
noto
@a9b1ah Hello, noto!
@e7sa3b 123

### Show entry:
noto @a9b1ah
Hello, noto!

### Delete entry:
noto -d @a9b1ah
```

### Build from source

```bash
cmake CMakeLists.txt && make
```
