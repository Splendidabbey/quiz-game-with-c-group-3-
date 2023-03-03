#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the quiz question
struct Question {
    char text[100];
    char choices[4][50];
    int correct_choice;
};

// Define an array of quiz questions
struct Question questions[] = {
    {
        "What is the basic data type to store an integer value?",
        {"A. int", "B. char", "C. float", "D. double"},
        0
    },
    {
        "What is the basic data type to store a single character?",
        {"A. int", "B. char", "C. float", "D. double"},
        1
    },
    {
        "What is the basic data type to store a decimal number?",
        {"A. int", "B. char", "C. float", "D. double"},
        2
    },
    {
        "What is the correct way to declare a constant in C?",
        {"A. #define CONSTANT 100", "B. const CONSTANT = 100", "C. CONSTANT = 100", "D. constant CONSTANT = 100"},
        0
    },
    {
        "What is the output of the following code? \n int x = 5, y = 10; \n printf(\"%d\", x + y);",
        {"A. 5", "B. 10", "C. 15", "D. 50"},
        2
    },
    {
        "What is the output of the following code? \n int i = 0; \n while (i < 5) { \n printf(\"%d \", i); \n i++; \n }",
        {"A. 0 1 2 3 4", "B. 1 2 3 4 5", "C. 0 1 2 3 4 5", "D. 1 3 5"},
        0
    },
    {
        "What is the output of the following code? \n int x = 5; \n if (x < 10) { \n printf(\"%d\", x); \n }",
        {"A. 5", "B. 10", "C. 15", "D. Error"},
        0
    },
    {
        "What is the output of the following code? \n int x = 5; \n int y = x++; \n printf(\"%d %d\", x, y);",
        {"A. 5 6", "B. 6 5", "C. 5 5", "D. 6 6"},
        1
    }
};

// Define a function to display a quiz question and its choices
void display_question(struct Question q) {
    printf("%s\n", q.text);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", q.choices[i]);
    }
}

int main() {
    // Declare variables
    int num_questions = sizeof(questions) / sizeof(questions[0]);
    int score = 0;
    int response;
    
    // Loop through each quiz question
    for (int i = 0; i < num_questions; i++) {
        // Display the question and its choices
        display_question(questions[i]);
        
        // Get the user's response
        printf("Enter your response 0,1,2,3 (A is 0, B is 1, C is 2, and D is 3): ");
        
        // to get user input- case insensitive
        char userInput[2];

   printf("Enter a letter (a, b, c, or d): ");
   scanf("%1s", userInput);

   if (strcasecmp(userInput, "a") == 0) {
      response = 0;
      printf("You entered 'a'.\n");
   } else if (strcasecmp(userInput, "b") == 0) {
      response = 1;
      printf("You entered 'b'.\n");
   } else if (strcasecmp(userInput, "c") == 0) {
      response = 2;
      printf("You entered 'c'.\n");
   } else if (strcasecmp(userInput, "d") == 0) {
      response = 3;
      printf("You entered 'd'.\n");
   } else {
      response = 5;
      printf("You did not enter a valid letter.\n");
   }
        
        
        //scanf("%d", &response);
        
        // Check if the user's response is correct
        if (response == questions[i].correct_choice) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
            score++;
        }
    }
    
    // Display the user's final score
    printf("Quiz complete! You got %d out of %d questions correct.\n", score, num_questions);
    
    return 0;
}