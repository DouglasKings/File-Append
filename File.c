#include <stdio.h> // Include standard I/O library for input/output operations
#include <string.h> // Include string library for string manipulation functions like strcspn

// Function prototype declaration for appendToFile
void appendToFile(char* text, char* fileName);

int main() {
    // Declare an array of chars named 'text' with a size of 100 to store the text to be appended
    char text[100];
    // Similarly, declare another array of chars named 'fileName' with a size of 50 to store the file name
    char fileName[50];

    // Print a message asking the user to enter the text to append
    printf("Enter the text to append: ");
    // Read the user's input into the 'text' variable using fgets, which reads until a newline character or EOF
    fgets(text, sizeof(text), stdin); 

    // Print a message asking the user to enter the file name
    printf("Enter the file name: ");
    // Read the user's input into the 'fileName' variable using fgets, similar to above
    fgets(fileName, sizeof(fileName), stdin); 

    // Remove the trailing newline character from the 'text' variable by setting the character at the position of the newline to the null character ('\0')
    text[strcspn(text, "\n")] = '\0'; 
    // Do the same for the 'fileName' variable
    fileName[strcspn(fileName, "\n")] = '\0'; 

    // Call the appendToFile function, passing the text and file name as arguments
    appendToFile(text, fileName);

    return 0; // Return 0 to indicate successful execution of the program
}

// Function definition for appendToFile
void appendToFile(char* text, char* fileName) {
    FILE *file; // Declare a pointer to a FILE structure

    // Attempt to open the file in append mode ('a+') using fopen
    file = fopen(fileName, "a+");
    // Check if the file was successfully opened
    if (file == NULL) {
        // If the file couldn't be opened, print an error message and return from the function
        printf("Failed to open the file.\n");
        return;
    }

    // Write the text to the file using fprintf, which writes formatted output to the file
    fprintf(file, "%s", text);
    // Print a success message indicating that the text has been appended
    printf("Text appended successfully.\n");

    // Close the file using fclose to release the resources associated with the file
    fclose(file);
}