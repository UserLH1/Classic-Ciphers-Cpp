# Classic Cipher Implementation

## Description
This application implements two classic encryption algorithms:
1. **Substitution Cipher** (Caesar with shift=3)
2. **Transposition Cipher** (column-based with configurable key)

## Project Structure
- `app/include/` - Header files
- `app/src/` - Source files
- `app/Makefile` - Build configuration
- `tests/` - Test files with input and output examples

## Algorithms
### Substitution Cipher
A Caesar cipher with a fixed shift of 3 positions.
- Example: "Hello" → "Khoor"
- Characters outside the alphabet remain unchanged

### Transposition Cipher  
Rearranges characters by writing in rows and reading by columns.
- Uses a key to determine the number of columns
- Pads incomplete blocks with a special character
- Example: "Hello World" with key=4 creates a grid:
    ```
    H e l l 
    o   W o 
    r l d ?
    ```
    And encrypts to: "Hor e lWd lo?"

## How to Compile
1. Navigate to the app directory:
     ```bash
     cd app
     ```
2. Run make:
     ```bash
     make
     ```
3. The executable will be generated in dist/app

## How to Run
### For Substitution Cipher:
```bash
# Encryption
./dist/app -e ../tests/input.txt -o ../tests/output_substitution_enc.txt --sub

# Decryption
./dist/app -d ../tests/output_substitution_enc.txt -o ../tests/output_substitution_dec.txt --sub
```
### For Transposition Cipher (with key=4):
```bash
# Encryption
./dist/app -e ../tests/input.txt -o ../tests/output_transposition_enc.txt --trans 4

# Decryption
./dist/app -d ../tests/output_transposition_enc.txt -o ../tests/output_transposition_dec.txt --trans 4
```

## Command Line Arguments
- `-e <inputFile>`: Encrypt the content of the input file
- `-d <inputFile>`: Decrypt the content of the input file
- `-o <outputFile>`: Specify the output file
- `--sub`: Use substitution cipher
- `--trans <key>`: Use transposition cipher with the specified key

## Examples with Results
Input text: `Hello World 123`

- Substitution encryption: `Khoor Zruog 123`
- Transposition encryption (key=4): `Hor1 e l2lWd3lo`

## Notes
- For Windows, use `dist\app.exe` instead of `./dist/app`
- Make sure the input files exist before running the command