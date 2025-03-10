# Classic Cipher with 2 algorithms

## Description
The app implements two basic ciphers:
1. **Substitution** (Caesar with shift=3)
2. **Transposition** (with a number of columns as the key)

## Structure
- `include/` - header files
- `src/` - source files
- `Makefile` - for compilation
- Test files in `../testcases/`

## How to compile?
1. `cd app`
2. `make`
3. `app` (executable) is generated.

## How to run?
Example (from `app/`):
```bash
./app -e ../testcases/input1.txt -o ../testcases/output_substitution_enc.txt --sub
./app -d ../testcases/output_substitution_enc.txt -o ../testcases/output_substitution_dec.txt --sub
./app -e ../testcases/input1.txt -o ../testcases/output_transposition_enc.txt --trans 4
./app -d ../testcases/output_transposition_enc.txt -o ../testcases/output_transposition_dec.txt --trans 4
```
