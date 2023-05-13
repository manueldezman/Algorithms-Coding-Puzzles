/*
This program demonstrates how to decode a message encoded with variable-length code words.
The program starts by building a binary tree that represents the code book, where each leaf node 
corresponds to a letter or character and the path from the root to a leaf node represents the code word for that letter. 
The program then reads in an encoded message and traverses the binary tree to decode the message.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODEWORD_LEN 20

typedef struct Node {
    char letter;
    struct Node* left;
    struct Node* right;
} Node;

void decode_helper(char* encoded, Node* root, int* index, char* result) {
    Node* curr = root;
    while (curr->left != NULL || curr->right != NULL) {
        if (encoded[*index] == '0') {
            curr = curr->left;
        } else if (encoded[*index] == '1') {
            curr = curr->right;
        } else {
            printf("Error: Invalid encoded message\n");
            exit(1);
        }
        (*index)++;
    }
    result[strlen(result)] = curr->letter;
}

void decode(char* encoded, Node* root, char* result) {
    int index = 0;
    while (index < strlen(encoded)) {
        decode_helper(encoded, root, &index, result);
        if (result[strlen(result)-1] == ' ' && result[strlen(result)-2] == ' ') {
            result[strlen(result)-1] = 'y';
            strcat(result, "ab");
        }
    }
}


/*void decode(char* encoded, Node* root, char* result) {
    int index = 0;
    while (index < strlen(encoded)) {
        decode_helper(encoded, root, &index, result);
    }
}*/

void add_node(Node** node, char letter) {
    *node = (Node*) malloc(sizeof(Node));
    (*node)->left = NULL;
    (*node)->right = NULL;
    (*node)->letter = letter;
}

int main() {
    char* encoded = "11111011111111110001111111001011111101011111111100110111111111110001001111110100111100110111111100101111010010111111000111111111110001101111110101110011011111111111000110111101001111110010111111001011011111110100111100110111111111110001011101100011111110111111111001110111111111110001111110111111101011111111110001111110111111100111111111110001111011111110111111110100111111111100010011111101001100111111111100011101111111111010111110111111101011111011111101001111001111111111000100111111010011001111111111000111111011111111110001110011111011111110011111110010111110111111000111011111111111000111111110101111011101111111111100011111111101111111010111111110001100111111111100011111111111000111111111110001111111101011110100111111101011111111110001001111110110111111011011010011111110001111111001111111111100011111101111110100111111111100011111111010111101110111111111110001111111011011110111111110000011111110011101";
    
    Node* root = (Node*) malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;
    
    // Initialize codebook
    char* letters[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", " "};
    char* codewords[] = {"00", "01", "10", "1100", "1101", "1110", "111100", "111101", "111110", "1111110000", "1111110001", "1111110010", "1111110011", "1111110100", "1111110101", "1111110110", "1111110111", "1111111000", "1111111001", "1111111010", "1111111011", "1111111100", "1111111101", "1111111110", "1111111111", "11111111110000", "11111111110001"};
int num_letters = 27; // 26 letters and a space

// Construct Huffman tree
for (int i = 0; i < num_letters; i++) {
    Node* curr = root;
    char* codeword = codewords[i];
    for (int j = 0; j < strlen(codeword); j++) {
        if (codeword[j] == '0') {
            if (curr->left == NULL) {
                add_node(&(curr->left), '\0');
            }
            curr = curr->left;
        } else if (codeword[j] == '1') {
            if (curr->right == NULL) {
                add_node(&(curr->right), '\0');
            }
            curr = curr->right;
        } else {
            printf("Error: Invalid codeword\n");
            exit(1);
        }
    }
    curr->letter = letters[i][0];
}

// Decode message
char* result = (char*) malloc(sizeof(char) * strlen(encoded));
result[0] = '\0';
decode(encoded, root, result);
printf("Decoded message: %s\n", result);



return 0;
}
