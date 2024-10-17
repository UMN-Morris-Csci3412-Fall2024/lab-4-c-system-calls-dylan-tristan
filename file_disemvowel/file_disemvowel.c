#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024

// Function to find all vowels
int is_vowel(char c){
    char lower_c = tolower(c);
    return lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u';
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    int out_index = 0;
    for (int i = 0; i < num_chars; i++) {
        if (!is_vowel(in_buf[i])) {
            out_buf[out_index] = in_buf[i];
            out_index++;
        }
    }
    return out_index;
}

void disemvowel(FILE *inputFile, FILE *outputFile) {
    char in_buf[BUF_SIZE];
    char out_buf[BUF_SIZE];
    size_t num_read;
    
    while ((num_read = fread(in_buf, sizeof(char), BUF_SIZE, inputFile)) > 0) {
        int num_non_vowels = copy_non_vowels(num_read, in_buf, out_buf);
        fwrite(out_buf, sizeof(char), num_non_vowels, outputFile);
    }
}


int main(int argc, char *argv[]) {
    FILE *inputFile = stdin;
    FILE *outputFile = stdout;
    
    if (argc > 1) {
        inputFile = fopen(argv[1], "r");
        if (inputFile == NULL) {
            perror("Error opening input file");
            return 1;
        }
    }

    if (argc > 2 ) {
        outputFile = fopen(argv[2], "w");
        if (outputFile == NULL) {
            perror("Error opening output file");
            fclose(inputFile);
            return EXIT_FAILURE;
        }
    }

    (disemvowel(inputFile, outputFile));

    if (inputFile != stdin) fclose(inputFile);
    if (outputFile != stdout) fclose(outputFile);

    return EXIT_SUCCESS;
    
    // // Read in an input file from first arg
    // FILE *file = fopen(argv[0],"r+");
    // if (file == NULL) {
    //     perror("Error opening file");
    //     return 1;
    // }
    // fclose(file);
    
    // if (argc == 1) {
    //     // Print output of disemvowel
    // } else {
    //     // Write output of disemvowel to output file
    //     // disemvowel(*file, );
    // }
    // disemvowel(input, output);
}

