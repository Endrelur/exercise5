#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

// These should be constant, but I was not able to find a suitable solution where they are constant
// and where I can return a wrapped character when there is no match in char_to_encoding(char c) 
char AND[] = "&amp;";
char LEFT_ANGLE_BRACKET[] = "&lt;";
char RIGHT_ANGLE_BRACKET[] = "&gt;";

// Container to hold the character when char_to_encoding(char c)
char WRAPPER_BUFFER[] = " ";

char * char_to_encoding(char c) {
    switch (c) {
        case '&':
            return AND;
            break;
        case '<':
            return LEFT_ANGLE_BRACKET;
            break;
        case '>':
            return RIGHT_ANGLE_BRACKET;
            break;
        default:
            WRAPPER_BUFFER[0] = c;
            return WRAPPER_BUFFER;
    }
}

int append_encoding(char buffer[], const char *encoding, int index, int offset) {
    for (int i = 0; i < strlen(encoding); i++) {
        buffer[index + offset] = encoding[i];
        offset++;
    }

    return --offset;
}

/**
 * Algorithm
 * 1. Fnd required buffer length for the encoding
 * 2. Write encoded string to buffer 
 */
char * encode(char *input) {
    // First pass: Find length of the new buffer
    int length = 0;
    for (int i = 0, c = *(input + i); c != '\0'; i++, c = *(input + i)) {
        char * sub_string = char_to_encoding(c);
        length += strlen(sub_string);
    }

    // Allocate buffer to hold the encoded string 
    char *buffer = malloc(length);
    if (buffer == NULL) {
        printf("Failed to allocate buffer of length %d\n", length);
        return NULL;
    }

    // Second pass: Copy the string over to the buffer and encode the special characters
    int offset = 0;
    for (int i = 0; i < strlen(input); i++) {
        char * sub_string = char_to_encoding(input[i]);
        offset = append_encoding(buffer, sub_string, i, offset);
    }

    return buffer;
}


int main(int argc, char const *argv[]) {
    // char *buffer = "";
    // char *buffer = "&";
    char *buffer = "<script>&&&</script>";

    buffer = encode(buffer);
    if (buffer == NULL)
        return -1;
    
    printf("%s\n", buffer);
    free(buffer);

    return 0;
}