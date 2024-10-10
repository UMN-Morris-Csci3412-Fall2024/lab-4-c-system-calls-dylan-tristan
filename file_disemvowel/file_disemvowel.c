#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

// Function to find all vowels
int is_vowel(char c){
    char lower_c = tolower(c);
    return lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u';
}

void disemvowel(FILE *input, FILE *output) {
    char c;
    while((c = fgetc(input)) != EOF) {
        if (!is_vowel(c)) {
            fputc(c, output);
        }
    } 
}


int main(int argc, char *argv[]) {
    FILE *input = stdin;
    FILE *output = stdout;
    
    // Read in an input file from first arg
    FILE *file = fopen(argv[0],"r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    fclose(file);
    
    if (argc == 1) {
        // Print output of disemvowel
    } else {
        // Write output of disemvowel to output file
        // disemvowel(*file, );
    }
    disemvowel(input, output);
}

