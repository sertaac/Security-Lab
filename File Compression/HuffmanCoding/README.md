---
# Huffman Coding — Python Implementation

This module provides a complete, interactive implementation of the **Huffman Coding** algorithm for text compression. It builds a binary tree based on character frequencies and assigns the shortest codes to the most frequent characters.

---

## Overview

**Huffman Coding** is a lossless compression algorithm that uses variable-length codes for encoding characters based on their frequencies in the input. It guarantees prefix-free codes, meaning no code is a prefix of another.

This implementation includes:
- Huffman Tree construction using a min-heap.
- Tree traversal for code generation.
- Console-based interface for real-time encoding.
- Compression ratio display.

---

## File

> `HuffmanCode_v0.1.py`

### Features
- Object-oriented structure using a `Node` class.
- Frequency analysis with dictionaries.
- Heap-based priority queue (min-heap via `heapq`).
- Traversal to assign binary codes to characters.
- Encodes user-input string and displays:
  - Character-to-code mapping
  - Encoded bit stream
  - Compression ratio (estimated)

---

## How to Run

```
cd HuffmanCoding
python3 HuffmanCode_v0.1.py
```

Then input a text string when prompted (up to any length).

---

## Sample Output

```
Please enter a text to encode: 
sertaaac

Character to Huffman Code Mapping:
't': '00'
's': '010'
'r': '011'
'c': '100'
'e': '101'
'a': '11'

Encoded Output:
[ 010 101 011 00 11 11 11 100 ]

Compression Ratio: 75.00% savings
```

> Note: Compression ratio is a rough estimate based on average bit length compared to fixed 8-bit ASCII encoding.

---

## Structure Breakdown

* **Node Class**: Represents a tree node, with frequency and child links.
* **build\_frequency\_dictionary()**: Counts character occurrences.
* **create\_huffman\_tree()**: Builds binary tree from frequencies.
* **create\_encoding()**: Recursively walks the tree to generate codes.
* **main()**: Ties everything together and displays results.

---

## Requirements

* Python 3.10+
* No external dependencies

---

## Author

Created by **Sertaç Ataç**
Version: `v0.1`
Date: `28.06.2025`

---

## Notes & Improvements

* Currently only handles **encoding**.
* Future additions may include:

  * Decoding logic
  * Bit-level storage support
  * File compression instead of just strings

Feel free to extend or contribute!
