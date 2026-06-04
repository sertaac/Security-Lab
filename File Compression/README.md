# File Compression Repository 📦

This repository is dedicated to exploring and implementing various **file compression algorithms**. Each folder in this repository represents a specific algorithm or approach, complete with source code, documentation, and practical examples.

---

## 🔍 Purpose

The goal is to study how different compression algorithms work under the hood and to share working C or Python implementations with detailed explanations and usage examples. This is a learning-oriented project aimed at building a deeper understanding of how file compression works.

---

## 📁 Current Modules

### [`LZW/`](./LZW)

The first implemented algorithm is **Lempel-Ziv-Welch (LZW)**. Inside this folder:

- ✅ A working C implementation.
- ✅ Dictionary-based compression logic.
- ✅ Console-based interaction for compressing custom strings.
- ✅ Comparison between original and compressed sizes.

> 📄 Check out the [`README.md`](./LZW/README.md) inside the folder for more details.

### [`HuffmanCoding/`](./HuffmanCoding)

A second module implementing **Huffman Coding**. Inside this folder:

- ✅ A working Python implementation.
- ✅ Frequency-based binary tree construction.
- ✅ Character-to-binary encoding via Huffman Tree traversal.
- ✅ Console-based input and encoding visualization.
- ✅ Displays compression ratio and code mappings.

> 📄 Check out the [`HuffmanCode_v0.1.py`](./HuffmanCoding/v0.1/HuffmanCode_v0.1.py) script for a complete demonstration.

---

## 🔧 Requirements

- For LZW: GCC or any standard C compiler.
- For Huffman: Python 3.10+ (due to type hints like `list[str]`)
- Basic understanding of C or Python programming and terminal commands.

---

## 🛠️ Upcoming Plans

Planned additions:
- Run-Length Encoding (RLE)
- DEFLATE (if manageable)
- LZ77 / LZ78
- Performance benchmarks

---

Feel free to use, modify, and share.
