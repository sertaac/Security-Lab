#######################################
##                                   ##
##            This is my             ##
##     file compressor program's     ## 
##       python implementation       ##
##    Algorithm: Lempel-Ziv-Welch    ##
##            23.06.2025             ##
##           Sertac Atac             ##
##                                   ##
#######################################

MAX_DICT_SIZE = 10000

# Initialize dictionary and nextKey values #
def initDic():
    dictionary = {chr(i): i for i in range(256)}
    return dictionary, 256

#  Main Compression Function  #
# Returns to Compressed Output #
def compressToLZW(inputStr):
    dictionary, nextKey = initDic()
    compressedData = []
    w = ""

    """
    Steps
    Iterate next character c through input string

    # If wc is in dictionary:
    1. Give no output
    2. Set w to wc

    # If wc is not in dictionary
    1. Add wc to dictionary with nextKey
    2. Increase nextKey by 1
    3. Give output as w (not in here but print functions)
    4. Set w to c
    """
    for c in inputStr:
        wc = w + c
        
        if wc in dictionary:
            w = wc
        else:
            dictionary[wc] = nextKey
            nextKey += 1
            compressedData.append(dictionary[w])
            w = c
        
    #  Loop is finished so give the last output as w  #
    # (Add w to compressedData so output can be given) #
    if w:
        compressedData.append(dictionary[w])

    return compressedData

def printCompressedData(compressedData):
    # Final Output from Compressed Data #
    #     Format: [ Key1 Key2 ... ]     #

    print("Compressed data:")
    print("[", ' '.join(map(str, compressedData)), "]")

def printSizeComparison(inputStr, compressedData):
    # Comparison between original data size and compressed data size #
    #           Checks if compression is effective or not            #

    print(f"Original data size: {len(inputStr)} bytes")
    print(f"Compressed data size: {len(compressedData) * 4} bytes")  # assuming 4-byte ints
    if len(compressedData) * 4 < len(inputStr):
        print("Compression successful!")
    else:
        print("Compression not effective.")

def main():
    inputStr = input("Please enter a string up to 1000 characters to compress: ")[:1000]
    compressedData = compressToLZW(inputStr)
    printCompressedData(compressedData)
    printSizeComparison(inputStr, compressedData)

if __name__ == "__main__":
    main()