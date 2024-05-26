#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void appendText(char *text, int arraySize) {
    char userInput[1000];
    printf("Please, enter text:\n");
    scanf("%999[^\n]", userInput);
    int inputLength = strlen(userInput);
    int currentSize = strlen(text);
    if(currentSize + inputLength >= arraySize){
        text = (char *)realloc(text, (currentSize + inputLength + 2) * sizeof(char));
        arraySize = currentSize + inputLength + 2;
    }
    strcat(text, userInput);
    printf("Text was added successfully");
}

void startNewLine(char *text){
    strcat(text, "\n");
}



int main() {
    char *text =(char*) calloc(100,sizeof(char));
    int arraySize = 100;
    printf("Commands:\n"
           "1. Append text .\n"
           "2. Start the new line.\n"
           "3. Saving information in the file.\n"
           "4. Loading information from the file.\n"
           "5. Print current text.\n"
           "6. Insert the text by line and symbol index.\n"
           "7. Search text.\n"
           "8. Exit.\n");
    int command;
    while (command!=8){
        printf("\nPlease, enter a number of command:");
        scanf("%d", &command);
        getchar();
        if (command < 1 || command > 8) {
            printf("Invalid command.\n");
        }
        if (command == 1){
            appendText(text, arraySize);
        }
        if(command == 2){
            startNewLine(text);
        }
    }
    printf("Ciao!");
    free(text);
    return 0;
}
