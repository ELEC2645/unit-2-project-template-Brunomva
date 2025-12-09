#include <stdio.h> // this library provide printf, scanf, fgets and getchar
#include <string.h>// provides strstr for key word search, strcspn to remove new line
#include <stdlib.h> // provides atoi,strtod, exit
#include "funcs.h" //this library contains all the function prototypes for the program and connects the code here to the other files

// This struct stores one formula: a description + the function that calculates it
typedef struct {
    const char *description;   // text the user searches for
    void (*func)(void);        // function to run when selected
} FormulaEntry;


// List of all formulas the search engine can find
static const FormulaEntry formula_table[] = {


    // --- Potential Divider discriptions for key word search and the fuction for the formulas ---
    { "Potential divider: find Vout", find_Vout },
    { "Potential divider: find Vin",  find_Vin },
    { "Potential divider: find R2",   find_R2 },
    { "Potential divider: find R1",   find_R1 },


    // --- Ohm's Law discriptions and the function used to do calculations for each formula ---
    { "Ohm's Law: find V", find_V },
    { "Ohm's Law: find I", find_I },
    { "Ohm's Law: find R", find_R },


    // --- Power (P = V I) has the discription of the formula and the function of the  formula for each variable ---
    { "Power PVI: find P", find_P_PVI },
    { "Power PVI: find I", find_I_PVI },
    { "Power PVI: find V", find_V_PVI },


    // --- Power (P = I^2 R) has the discription of the formula and the function of the  formula for each variable ---
    { "Power PIR: find P", find_P_PIR },
    { "Power PIR: find I", find_I_PIR },
    { "Power PIR: find R", find_R_PIR },


    // --- Power (P = V^2 / R) has the discription of the formula and the function of the  formula for each variable ---
    { "Power PVR: find P", find_P_PVR },
    { "Power PVR: find V", find_V_PVR },
    { "Power PVR: find R", find_R_PVR },


    // --- Capacitance has the discription of the formula and the function of the  formula for each variable---
    { "Capacitance: find C", find_C_CQV },
    { "Capacitance: find Q", find_Q_CQV },
    { "Capacitance: find V", find_V_CQV }
};


// I have used enum beacuse the size of the array is not determined yet, it is only know when the user types a keyword, and this is the reason why I did not use int
// here formual count stores the amount of formulas there are, sizeof formula table is the size of the table in total and sizeof formula_table[0] is the size of the first stop in the table
enum { FORMULA_COUNT = sizeof formula_table / sizeof formula_table[0] };




// This is the actual search menu funcgtion called from main menu
void search_menu(void) {
    char keyword[100]; // string with created that allows 99 characters to be input

// this section with printf prints on the terminal whatever is inside the brackets
    printf("\n----------- Formula Search -----------\n");
    printf("Type any keyword (example: Vout, Vin, R2, Ohm, Power...)\n");
    printf("Search: ");


    // this get the keyword from the user, again used fgets because it safer than fgets
    if (!fgets(keyword, sizeof keyword, stdin)) {
        return; // if input fails, just return (
    }


    // Remove the newline so it doesn't break comparisons, an example is if the a keyword is Vout, when I input Vout in fgets it reads Vout\n 
    // \n happens when enter is pressed so this line of code removes the enter and just leaves the fgets input as Vout 
    keyword[strcspn(keyword, "\n")] = '\0';


    // this if statement makes sure if the first character when the user inputs a value is enter makes sure to stop the program
    // prints search is cancelled and goes back to the main menu
    if (keyword[0] == '\0') {
        printf("Search cancelled.\n");
        go_back_to_main();
        return;
    }


    int matches[FORMULA_COUNT];// array that has the same value as the FORMULA_COUNT
    int match_count = 0; // variable that is going to be used to count the number of results after keyword is input


    printf("\nResults for \"%s\":\n", keyword); // prints the keyword input by the user


    // Go through the whole formula list and check if the keyword appears in the description
    for (int i = 0; i < FORMULA_COUNT; ++i) { // the amount of times the  loop repeats is equal to FORMULA_COUNT
        if (strstr(formula_table[i].description, keyword)) { 
            matches[match_count] = i; // 
            printf("%d) %s\n", match_count + 1, formula_table[i].description);
            match_count++;
        }
    }
    //the previous if statement goes in the for loop uses strstr to find the keyword from the formula_table array in the discription side of the struct
    //matches[match_count] stores the index of the match,
    // in the printf statement match_count + 1 because the we want the numbers to start from 1 onwards instead of 0 onwards because initial value of macth_count is 0


    // If nothing matched print the statement then go back to the main menu
    if (match_count == 0) {
        printf("No formulas found.\n");
        go_back_to_main();
        return;
    }


    
    char choice_buf[16]; //creates a string with size 16
    printf("\nChoose a formula number, or press 'b' to go back: ");//Asks the user which formula they want to run


    if (!fgets(choice_buf, sizeof choice_buf, stdin)) {
        return; // this use fgets inside of  and if statement if there is an error with the input it just returns
    }


    // Remove newline from enter
    choice_buf[strcspn(choice_buf, "\n")] = '\0';


    // If   b/B is typed then return to the menu
    if (choice_buf[0] == 'b' || choice_buf[0] == 'B') {
        go_back_to_main();
        return;
    }


    //atoi  Converts input to a number and stores it in choice
    int choice = atoi(choice_buf);


    // the if statement makes sure that the number is in between 1 and the total amount of results
    if (choice < 1 || choice > match_count) {
        printf("Invalid option.\n");
        go_back_to_main();
        return;
    }


    // Get the real index form fgets 
    //here choice - 1 means the if we input 1 for choice matches becomes zero because the count starts from 0,1,2...
    int index = matches[choice - 1];

// prints the formula discriptions and enumerates them 
    printf("\n--- Running: %s ---\n", formula_table[index].description);


    // Call the selected functions obtained form the search and enumerates them and whatever number I press it opens the formula assigned
    // to that number
    formula_table[index].func();


    // Same behaviour as other menus 
    go_back_to_main();
}


