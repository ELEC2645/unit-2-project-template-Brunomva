#include <stdio.h>
#include <stdlib.h> 
#include "funcs.h"




void main_menu(void) {
    print_main_menu();
    int input = get_user_input();
    select_menu_item(input);
}

void clear_input_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { //used to flush after scanf
        // discard everything up to and including the newline 
    }
}

int get_user_input(void) {
    int input;
    printf("\nSelect item: ");
    scanf("%d", &input);  // assume valid input for this activity
     clear_input_buffer();
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
    printf("|\t1. Potential Divider\t|\n");
    printf("|\t2. Subtraction\t|\n");
    printf("|\t3. Multiplication\t|\n");
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
    int input = get_user_input();
     select_variable_PotentialDivider(input);
     

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
    printf("\n##### PRESS #####\n");
    printf("|\t1. to calculte Vout\t|\n");
    printf("|\t2. to calculte Vin\t|\n");
    printf("|\t3. to calculte R2\t\n");
    printf("|\t4. to calculte R1\t\t|\n");
    printf("|\t5. Exit\t\t\t|\n");
    printf("---------------------------------\n");


}


//inside menu 1 potential divider
// When Vout is the subject
void find_Vout(void){
    char buf[100];
   
    double Vin;
    double R1;
    double R2;
    printf("\n Enter value for Vin\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        Vin  = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("Vin = %f\n", Vin); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for R1\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        R1 = strtod(buf, NULL);
        printf("R1 = %f\n", R1);
    }
     // same method used as the previous if statement
    printf("\n Enter value for R2\n"); 
    if (fgets(buf, sizeof buf, stdin)) {
        R2  = strtod(buf, NULL);
        printf("R2 = %f\n", R2);
    }

    double Vout = Vin * R2/(R2+R1);// here a variable is created (Vout) to store the value of the calculation of the values that where input previously

    printf("\n Vout= %f\n",Vout); //Prints value of Vout
}



void find_Vin(void){
    char buf[100];
   
    double Vout;
    double R1;
    double R2;
    printf("\n Enter value for Vout\n");
    if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        Vout = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("Vin = %f\n", Vout); // here the value is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for R1\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        R1 = strtod(buf, NULL);
        printf("R1 = %f\n", R1);
    }
     // same method used as the previous if statement
    printf("\n Enter value for R2\n"); 
    if (fgets(buf, sizeof buf, stdin)) {
        R2  = strtod(buf, NULL);
        printf("R2 = %f\n", R2);
    }

    double Vin = Vout * (R2+R1)/R2;// here a variable is created  to store the value of the calculation of the values that where input previously

    printf("\n Vin= %f\n",Vin); //Prints value 
}


void find_R2(void){
    char buf[100];
   
    double Vout;
    double R1;
    double Vin;
    printf("\n Enter value for Vout\n");
    if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        Vout = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("Vin = %f\n", Vout); // here the value  is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for R1\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        R1 = strtod(buf, NULL);
        printf("R1 = %f\n", R1);
    }
     // same method used as the previous if statement
    printf("\n Enter value for Vin\n"); 
    if (fgets(buf, sizeof buf, stdin)) {
        Vin  = strtod(buf, NULL);
        printf("R2 = %f\n", Vin);
    }

    double R2 = (Vout*R1)/(Vin-Vout);// here a variable is created  to store the value of the calculation of the values that where input previously

    printf("\n R2= %f\n",R2); //Prints value
}






void find_R1(void){
    char buf[100];
   
    double Vout;
    double Vin;
    double R2;
    printf("\n Enter value for Vout\n");
    if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        Vout = strtod(buf, NULL); // here the string buf is converted int0 decimal and stored into the variable Vin
        printf("Vin = %f\n", Vout); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for Vin\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        Vin = strtod(buf, NULL);
        printf("R1 = %f\n", Vin);
    }
     // same method used as the previous if statement
    printf("\n Enter value for R2\n"); 
    if (fgets(buf, sizeof buf, stdin)) {
        R2  = strtod(buf, NULL);
        printf("R2 = %f\n", R2);
    }

    double R1 = ((Vin*R2) -(Vout*R2) )/Vout;// here a variable is created  to store the value of the calculation of the values that where input previously

    printf("\n R1= %f\n",R1); //Prints value 
}


void select_variable_PotentialDivider(int input) {
    switch (input) {
        case 1:find_Vout(); break;
        case 2:find_Vin (); break;
        case 3: find_R2(); break;
        case 4:find_R1 (); break;


        case 5: printf("Exiting program...\n"); exit(0);
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}





