from typing import Optional
import heapq

class Node:
    """
    Represents a node in the Huffman tree.

    Attributes:
        value (Optional[str]): The character stored in the node (None for internal nodes)
        frequency (int): The frequency of the character
        left_child (Optional[Node]): Left child node
        right_child (Optional[Node]): Right child node
    """
    def __init__(self, value: Optional[str] = None, frequency: int = 0):
        self.value: Optional[str] = value
        self.frequency: int = frequency
        self.left_child: Optional[Node] = None
        self.right_child: Optional[Node] = None

    def __lt__(self, other: 'Node') -> bool:
        """Enable comparison between nodes based on frequency for heapq."""
        return self.frequency < other.frequency

    def is_leaf(self) -> bool:
        """Check if the node is a leaf node (contains a character value)."""
        return self.value is not None


def build_frequency_dictionary(text: str) -> dict[str, int]:
    """
    Builds a frequency dictionary for characters in the input text.

    Args:
        text: Input string to analyze

    Returns:
        Dictionary mapping characters to their frequencies
    """
    frequency_dictionary: dict[str, int] = {}
    for char in text:
        frequency_dictionary[char] = frequency_dictionary.get(char, 0) + 1
    return frequency_dictionary


def create_huffman_tree(text: str) -> Optional[Node]:
    """
    Constructs a Huffman tree from the input text.

    Args:
        text: Input string to encode

    Returns:
        Root node of the Huffman tree, or None for empty input
    """
    if not text:
        return None

    frequency_dictionary = build_frequency_dictionary(text)
    heap: list[Node] = []
    
    # Create leaf nodes and push them into the min-heap
    for char, freq in frequency_dictionary.items():
        heapq.heappush(heap, Node(value=char, frequency=freq))

    # Build the Huffman tree by merging nodes
    while len(heap) > 1:
        left_node = heapq.heappop(heap)
        right_node = heapq.heappop(heap)

        # Create new internal node with combined frequency
        merged_node = Node(frequency=left_node.frequency + right_node.frequency)
        merged_node.left_child = left_node
        merged_node.right_child = right_node

        heapq.heappush(heap, merged_node)

    return heapq.heappop(heap)


def create_encoding(root_node: Optional[Node]) -> dict[str, str]:
    """
    Generates Huffman codes by traversing the Huffman tree.

    Args:
        root_node: Root node of the Huffman tree

    Returns:
        Dictionary mapping characters to their Huffman codes
    """
    encoded_dictionary: dict[str, str] = {}
    
    def traverse(node: Optional[Node], current_code: str) -> None:
        if node is None:
            return
        
        if node.is_leaf():
            encoded_dictionary[node.value] = current_code  # type: ignore
        else:
            traverse(node.left_child, current_code + "0")
            traverse(node.right_child, current_code + "1")
    
    if root_node:
        traverse(root_node, "")
    return encoded_dictionary


def main():
    """Main function to demonstrate Huffman encoding."""
    print("Please enter a text to encode: ")
    text = input().strip()
    
    if not text:
        print("Error: Empty input string")
        return
    
    root_node = create_huffman_tree(text)
    if not root_node:
        print("Error: Failed to create Huffman tree")
        return
    
    huffman_dictionary = create_encoding(root_node)
    
    # Display the encoding results
    print("\nCharacter to Huffman Code Mapping:")
    for char, code in huffman_dictionary.items():
        print(f"'{char}': '{code}'")
    
    print("\nEncoded Output:")
    print("[ " + " ".join(huffman_dictionary[char] for char in text) +" ]")
    
    # Calculate compression ratio
    original_bits = len(text) * 8  # Assuming 8 bits for per character
    compressed_bits = sum(len(code) for code in huffman_dictionary.values())
    ratio = (original_bits - compressed_bits) / original_bits * 100
    print(f"\nCompression Ratio: {ratio:.2f}% savings")


if __name__ == "__main__":
    main()