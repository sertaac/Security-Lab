/*************************************/
/*                                   */
/*            This is my             */
/*            very first             */
/*      file compressor program.     */ 
/*    Algorithm: Lempel-Ziv-Welch    */
/*            20.10.2024             */
/*           Sertac Atac             */
/*                                   */
/*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DICT_SIZE 1000

/* Struct to represent dictionary entries, pairing a substring with a key */
typedef struct {
    char* subStr;  /* Pointer to the substring */
    int key;       /* Key associated with the substring */
} pairs;

/* Function prototypes */
size_t cmpdSizeCalc(int* compressed_data);              /* Calculate size of compressed data */
pairs* dictionarySet();                                 /* Initialize the dictionary */
int* strCompress(char* str, pairs* dictionary);         /* Compress a string */
int pairFinder(pairs* dictionary, char* key);           /* Find a key in the dictionary */
void insertNewKey(pairs* dictionary, char* currentStr, int currentKey); /* Insert a new key into the dictionary */
void freeDictionary(pairs* dictionary);                 /* Free the memory allocated for the dictionary */
void printResult(int* compressed_data);                 /* Print the compressed data */
void printSizeCmp(size_t firstSize, size_t secondSize); /* Compare and print sizes */

int main(void) {
    char str[1000]; /* Input string buffer */
    
    /* Prompt user for input string */
    printf("Please enter a string up to maximum 1000 characters ");
    printf("to be compressed by Lempel-Ziv-Welch algorithm: ");
    scanf("%999s", str);

    /* Initialize dictionary */
    pairs* newDictionary = dictionarySet();
    if(newDictionary == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return (EXIT_FAILURE);
    }

    /* Compress the string */
    int* compressed_data = strCompress(str, newDictionary);
    if(compressed_data == NULL) {
        freeDictionary(newDictionary);
        return (EXIT_FAILURE);
    }

    /* Output compressed results and size comparison */
    printResult(compressed_data);
    size_t originalSize = strlen(str); 
    size_t compressedSize = cmpdSizeCalc(compressed_data);
    printSizeCmp(originalSize, compressedSize);

    /* Free allocated memory */
    free(compressed_data);
    freeDictionary(newDictionary);
    return 0;
}

/* Calculate the size of the compressed data */
size_t cmpdSizeCalc(int* compressed_data) {
    int compressedSize = 0;
    for(int a = 0; compressed_data[a] >= 0; a++) {
        compressedSize += sizeof(compressed_data[a]); /* Add size of each integer */
    }
    return (size_t)compressedSize;
}

/* Initialize the dictionary with ASCII values */
pairs* dictionarySet() {
    pairs* newDict = (pairs*)malloc(MAX_DICT_SIZE * sizeof(pairs)); /* Allocate memory for dictionary */
    if(newDict == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    /* Initialize dictionary entries */
    for(int i = 0; i < MAX_DICT_SIZE; i++) {
        newDict[i].subStr = NULL; /* Set all substrings to NULL */
    }

    /* Populate dictionary with single-character ASCII entries */
    char temp[2];
    for(int i = 0; i < 256; i++) {
        temp[0] = (char)i; temp[1] = '\0';
        insertNewKey(newDict, temp, i);
    }

    return newDict;
}

/* Compress the input string using the LZW algorithm */
int* strCompress(char* str, pairs* dictionary) {
    int capacity = 100;                    /* Initial capacity for compressed data */
    int* compressedData = (int*)malloc(capacity * sizeof(int)); /* Allocate memory for compressed data */
    if(compressedData == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    /* Initialize compressed data with sentinel values */
    for(int z = 0; z < capacity; z++) { 
        compressedData[z] = -1;
    }

    /* Variables for compression logic */
    int i = 0, k = 0; /* Index for compressed data and new dictionary entries */
    char w[2], c[2];  /* Current sequence and next sequence */

    /* Main compression loop */
    for(int l = 0; l < strlen(str); ) {
        /* Extract current character into w */
        w[0] = str[l]; 
        w[1] = '\0';
        /* Extract next character into c */
        c[0] = (l + 1 < strlen(str)) ? str[l + 1] : '\0'; 
        c[1] = '\0';

        /* Check if w exists in dictionary */
        if(pairFinder(dictionary, w) < 0) {
            if(k + 256 >= MAX_DICT_SIZE) {
                fprintf(stderr, "Dictionary size exceeded.\n");
                free(compressedData);
                return NULL;
            }
            insertNewKey(dictionary, w, k + 256);
            k++;
        }

        /* Create a new substring w + c and check if it exists */
        char* currentStr = (char*)malloc((strlen(w) + strlen(c) + 1) * sizeof(char));
        if(currentStr == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            free(compressedData);
            return NULL;
        }
        strcpy(currentStr, w); strcat(currentStr, c);

        /* Insert new substring or continue searching */
        if(pairFinder(dictionary, currentStr) < 0) {
            insertNewKey(dictionary, currentStr, k + 256);
            compressedData[i++] = (int)w[0];
            k++;
            l++;
        } else { 
            /* Handle longer substrings */
            /* Move the pointer and adjust the substring */
            l += strlen(currentStr) - 1;
            if(l + 1 < strlen(str)) 
                c[0] = str[l + 1];
            
            /* Create a temporary substring to check further substrings */
            char* temp = (char*)malloc((strlen(currentStr) + 2) * sizeof(char));
            if(temp == NULL) {
                fprintf(stderr, "Memory allocation failed!\n");
                free(currentStr);
                free(compressedData);
                return NULL;
            }
            strcpy(temp, currentStr); 
            strcat(temp, c);
            free(currentStr);
            
            /* Check for substrings longer than three characters */
            while (pairFinder(dictionary, temp) >= 0 && l < strlen(str)) {
                l++;
                if(l + 1 < strlen(str)) 
                    c[0] = str[l + 1];

                /* Expand the temporary substring */
                size_t newSize = strlen(temp) + 2 + 1;
                char* newTemp = realloc(temp, newSize);
                if(newTemp == NULL) {
                    free(temp);
                    fprintf(stderr, "Memory allocation failed!\n");
                    free(compressedData);
                    return NULL;
                }
                temp = newTemp;
                strcat(temp, c);
            }
            
            /* Insert the new substring into the dictionary */
            insertNewKey(dictionary, temp, k + 256);
            compressedData[i++] = pairFinder(dictionary, temp);
            free(temp);
            k++;
        }

        /* Expand memory for compressed data if necessary */
        if(i >= capacity - 1) {
            capacity *= 2;
            int* newCompressedData = realloc(compressedData, capacity * sizeof(int));
            if(newCompressedData == NULL) {
                free(compressedData);
                fprintf(stderr, "Memory allocation failed!\n");
                return NULL;
            }
            compressedData = newCompressedData;
        }
    }

    return compressedData;
}

/* Insert a new key into the dictionary */
void insertNewKey(pairs* dictionary, char* currentStr, int currentKey) {
    dictionary[currentKey].subStr = (char*)malloc((strlen(currentStr) + 1) * sizeof(char));
    if(dictionary[currentKey].subStr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit((EXIT_FAILURE));
    }
    dictionary[currentKey].key = currentKey;
    strcpy(dictionary[currentKey].subStr, currentStr);
}

/* Find a key in the dictionary by matching substrings */
int pairFinder(pairs* dictionary, char* key) {
    for(int i = 0; i < MAX_DICT_SIZE; i++) {
        if(dictionary[i].subStr != NULL && strcmp(dictionary[i].subStr, key) == 0) {
            return i;
        }
    }
    return -1;
}

/* Free the memory allocated for the dictionary */
void freeDictionary(pairs* dictionary) {
    for(int i = 0; i < MAX_DICT_SIZE; i++) {
        free(dictionary[i].subStr);
    }
    free(dictionary);
}

/* Print the compressed data */
void printResult(int* compressed_data) {
    printf("Compressed data:\n[ ");
    for(int a = 0; compressed_data[a] >= 0; a++) {
        printf("%d ", compressed_data[a]);
    }
    printf("]\n");
}

/* Print comparison of original and compressed sizes */
void printSizeCmp(size_t firstSize, size_t secondSize) {
    printf("Original data size: %zu bytes\n", firstSize);
    printf("Compressed data size: %zu bytes\n", secondSize);
    if(secondSize < firstSize) {
        printf("Compression successful! Compressed size is smaller than original.\n");
    } else {
        printf("Compression was not effective. Compressed size is larger or equal to original.\n");
    }
}