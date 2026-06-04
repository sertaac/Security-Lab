---

# 📚 LZW Compression — C & Python Implementations

This folder contains two working implementations of the **Lempel-Ziv-Welch (LZW)** compression algorithm, one written in **C** and the other in **Python**. The purpose is to demonstrate and compare different approaches to implementing the same algorithm at both low-level and high-level languages.

---

## 🧠 Algorithm Overview

LZW is a **dictionary-based** lossless compression algorithm. It builds a dictionary of repeating sequences in the input data and replaces those sequences with shorter codes. The algorithm works by:

1. Initializing a dictionary with all possible single-character inputs.
2. Reading input data and checking if current sequence exists in the dictionary.
3. If it exists, extend the sequence.
4. If not, output the dictionary key of the previous sequence and add the new sequence to the dictionary.

---

## 📁 Folder Structure

```
LZW/
├── C/
│   └── MyFirstFileCompressor.c
│   └── README.md
├── Python/v0.1
│   └── LZWinPython_v.01
│   └── README.md
└── README.md  ← (You are here)
```

---

## Python Version

> 📄 File: `Python/LZWinPython_v.01`

### Features:
- Easy-to-read implementation using standard Python data structures.
- Handles strings up to 1000 characters from user input.
- Prints compressed output and compares compression size.
- Uses a dictionary of `{string: code}` pairs.

### How to Run:
```
python3 Python/lzw_compressor.py
```

---

## C Version

> 📄 File: `C/MyFirstFileCompressor.c`

### ✅ Features:
- Lower-level, memory-efficient implementation.
- Uses custom `struct` for dictionary management.
- Handles dictionary overflows gracefully.
- Dynamically allocates memory for compressed data and substrings.
- Includes size comparison and clear memory management.

### ▶️ How to Compile & Run:
```
cd C
gcc -o lzw_compressor lzw_compressor.c
./lzw_compressor
```

---

## Comparison

| Feature                  | Python Version         | C Version                |
|--------------------------|------------------------|--------------------------|
| Ease of use              | High                   | Requires compilation     |
| Performance              | Slower for large data  | Faster, low-level        |
| Memory management        | Automatic              | Manual (malloc/free)     |
| Educational clarity      | Beginner-friendly      | Shows inner workings     |

---

## 🧪 Sample Output

Example input:
```
Please enter a string: ABABABA
```

Python:
```
Compressed data:
[ 65 66 256 258 ]
Original data size: 7 bytes
Compressed data size: 16 bytes
Compression not effective.
```

C:
```
Compressed data:
[ 65 66 256 258 ]
Original data size: 7 bytes
Compressed data size: 16 bytes
Compression was not effective.
```

---

## 👤 Author

Created by **Sertaç Ataç**  
Python version date: `23.06.2025`  
C version date: `20.10.2024`

---

## 📌 Notes

- Compression efficiency varies depending on the input data pattern.
- Dictionary size is capped (`MAX_DICT_SIZE`) to prevent overflow.
- Compression may not always reduce size for very short or random inputs.

---

Feel free to improve or contribute with decompression logic, performance metrics, or cross-language benchmarks!
```
