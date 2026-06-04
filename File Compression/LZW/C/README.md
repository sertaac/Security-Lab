# File Compressor Program

This is a simple file compression program implemented in C using the **Lempel-Ziv-Welch (LZW)** compression algorithm. The program compresses a string inputted by the user and compares the size of the original string with the compressed data.

---

## Features

- Implements the **LZW compression algorithm**.
- Allows user input of up to **1000 characters**.
- Dynamically manages memory for compressed data and dictionary entries.
- Outputs:
  - Compressed data.
  - Original and compressed sizes.
  - Whether compression was effective.

---

## How It Works

1. **Dictionary Initialization**:
   - The program starts by initializing a dictionary with single-character ASCII values (0-255).
2. **Compression**:
   - The input string is read character by character.
   - Substrings are added to the dictionary if they do not already exist.
   - Compression replaces substrings with corresponding dictionary keys.
3. **Results**:
   - The compressed data is displayed.
   - The program calculates and prints the original and compressed sizes, indicating the effectiveness of the compression.

---

## Usage

### Prerequisites

- **C Compiler**: Ensure you have GCC or any compatible C compiler installed.
- **Operating System**: The program is cross-platform and works on Linux, Windows, and macOS.

### Compiling the Program

Use the following command to compile the program:

```bash
gcc -o file_compressor file_compressor.c
