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
void writeToFile(char *text) {
    FILE *out_file = fopen("C:\\Users\\User\\CLionProjects\\untitled\\my_text.txt", "w");
    if (out_file == NULL) {
        printf("Error! Could not open file\n");
        exit(1);
    }
    fprintf(out_file, "%s", text);
    fclose(out_file);
    printf("The data was successfully written to the file.");
}void  loadFromFile(){
    FILE *in_file = fopen("C:\\Users\\User\\CLionProjects\\untitled\\my_text.txt", "r");
    char myText[1000];
    fgets(myText, 1000, in_file);
    printf("Text fom file: %s",myText);
    fclose(in_file);
}
void printText(char *text){
    printf("Your text: %s", text);
}
void insertText(char **text, int *arraySize) {
    int lineNumber;
    int position;
    char userInput[1000];

    printf("Enter the line number: ");
    scanf("%d", &lineNumber);
    getchar();

    printf("\nEnter position number: ");
    scanf("%d", &position);
    getchar();

    printf("Please, enter text to insert:\n");
    scanf("%999[^\n]", userInput);
    getchar();

    int inputLength = strlen(userInput);
    int currentSize = strlen(*text);

    if (currentSize + inputLength >= *arraySize) {
        *arraySize = currentSize + inputLength + 2;
        *text = (char *)realloc(*text, *arraySize * sizeof(char));
        if (*text == NULL) {
            printf("Memory reallocation failed.\n");
            return;
        }
    }

    int currentLine = 1;
    int currentPosition = 0;
    char *ptr = *text;
    while (currentLine < lineNumber) {
        if (*ptr == '\n') {
            currentLine++;
        }
        ptr++;
        currentPosition++;
    }
    position += currentPosition;
    memmove(*text + position + inputLength, *text + position, currentSize - position + 1);
    strncpy(*text + position, userInput, inputLength);
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
        if(command==3){
            writeToFile(text);
        }
        if(command == 4){
            loadFromFile();
        }
        if (command == 5){
            printText(text);
        }
        if(command==6){
            insertText(&text,&arraySize);
        }
    }
    printf("Ciao!!!");
    free(text);
    return 0;
}
