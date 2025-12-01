#include <stdio.h>
#include <stdlib.h> 
#include "funcs.h"


/*

void main_menu(void) {
    print_main_menu();
    int input = get_user_input();
    select_menu_item(input);
}

int get_user_input(void) {
    int input;
    printf("\nSelect item: ");
    scanf("%d", &input);  // assume valid input for this activity
    return input;
}

void select_menu_item(int input) {
    switch (input) {
        case 1: menu_item_1(); break;
        case 2: menu_item_2(); break;
        case 3: menu_item_3(); break;
        case 4: menu_item_4(); break;


        case 5: printf("Exiting program...\n"); exit(0);
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}



void print_main_menu(void) {
    printf("\n----------- Main menu -----------\n");
    printf("|\t1. Addition\t|\n");
    printf("|\t2. Subtraction\t|\n");
    printf("|\t3. Multiplication\n");
    printf("|\t4. Division\t\t|\n");
    printf("|\t5. Exit\t\t\t|\n");
    printf("---------------------------------\n");
}

void go_back_to_main(void) {
    char input;
    // this do loop ensures user inputs 'b' or 'B' to go back
    // if user inputs other characters, it keeps prompting
    do {
        printf("\nEnter 'b' or 'B' to go back to main menu: ");
        scanf(" %c", &input);
    } while (input != 'b' && input != 'B');
    main_menu();
}



// --------------- Menu Item Functions ---------------

void menu_item_1(void) {
     print_menu_item_11();
    go_back_to_main();
}

void menu_item_2(void) {
    printf("\n>> Menu 2: Subtraction\n");
     printf("Enter a number\n");
    int num1;
    scanf("%d", &num1);
    printf("Enter a number\n");
    int num2;
    scanf("%d",&num2);
     int result = num1 - num2;
    printf("Result: %d\n", result);

  
    go_back_to_main();
}


void menu_item_3(void) {
     printf("\n>> Menu 2: Multiplication\n");
     printf("Enter a number\n");
    int num1;
    scanf("%d", &num1);
    printf("Enter a number\n");
    int num2;
    scanf("%d",&num2);
     int result = num1 * num2;
    printf("Result: %d\n", result);
    go_back_to_main();
   
}


void menu_item_4(void) {
    printf("\n>> Menu 2: Division\n");
     printf("Enter a number\n");
    int num1;
    scanf("%d", &num1);
    printf("Enter a number\n");
    int num2;
    scanf("%d",&num2);
     int result = num1/num2;
    printf("Result: %d\n", result);
    go_back_to_main();
}

//menus inside the menus

void print_menu_item_11(void){
    printf("\n----------- Potential divider -----------\n");
    printf("|\t1. Vin\t|\n");
    printf("|\t2. Vout\t|\n");
    printf("|\t3. R1\n");
    printf("|\t4. R2\t\t|\n");
    printf("|\t5. Exit\t\t\t|\n");
    printf("---------------------------------\n");


}
*/

//inside menu 1 potential divider
// When Vout is the subject
void find_Vout(void){
    char buf[100];
   
    double Vin;
    double R1;
    double R2;
    printf("\n Enter value for Vin");
    if (fgets(buf, sizeof buf, stdin)) {
        Vin  = strtod(buf, NULL);
        printf("Vin = %f\n", Vin);
    }
    printf("\n Enter value for R1");
     if (fgets(buf, sizeof buf, stdin)) {
        R1 = strtod(buf, NULL);
        printf("R1 = %f\n", R1);
    }
    printf("\n Enter value for R2"); 
    if (fgets(buf, sizeof buf, stdin)) {
        R2  = strtod(buf, NULL);
        printf("R2 = %f\n", R2);
    }

    double Vout = Vin * (R2/R2+R1);

    printf("\n Vout= %f\n",Vout);
}

