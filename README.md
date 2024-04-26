# MyCustomRundll

These my own alternative to MS rundll32.exe for my needs.

## Build

1. Clone the repository:

```bash
git clone https://github.com/PaNDa2code/rundll.git
```

2. Navigate to the project directory:

```bash
cd rundll
```

3. Run the make script (require `x86_64-w64-mingw-gcc`):

```bash
make
```

## Usage

I use `wine` to run it, like that:

```bash
wine rundll.exe MyDll.dll MyFunctionName
```
