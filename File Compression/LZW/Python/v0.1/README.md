# 🔐 My First File Compressor - LZW Algorithm (Python)

This is the python implementation for my program.
Created on **23.06.2025**.

## Features

- Pure Python implementation
- Efficient lookup and output structure
- Simple, educational, and extensible

---

## 📦 How It Works

1. Initializes a dictionary with all 256 ASCII characters.
2. Iterates through the input string.
3. Detects repeated patterns and assigns them codes starting from 256.
4. Outputs the list of integer codes representing the compressed version.

---

## 📈 Example

Input:
ABABABA

Output:
Compressed data:
[ 65 66 256 258 ]
Original data size: 7 bytes
Compressed data size: 16 bytes
Compression not effective.

---

## 🛠️ Future Optimizations (Planned)

- Replace `dict` with `array`, `bytearray`, or `sys.getsizeof()` for accurate memory usage.
- Add decompression logic.
- Support for binary file input/output.
- CLI interface using `argparse`.

---
