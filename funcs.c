#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
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
    printf("|\t2. Ohms Law\t|\n");
    printf("|\t3. Power equations\t|\n");
    printf("|\t4. Capacitance\t\t|\n");
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
    print_menu_item_22();
    int input = get_user_input();
    select_variable_OhmsLaw( input);

  
    go_back_to_main();
}


void menu_item_3(void) {
     print_menu_item_33();
     int input = get_user_input();
     select_equations_Power( input);

    go_back_to_main();
   
}


void menu_item_4(void) {
     print_menu_item_44();
     int input = get_user_input;
     select_variable_capacitance(input);
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

void print_menu_item_22(void){
    printf("\n----------- Ohms law -----------\n");
    printf("\n##### PRESS #####\n");
    printf("|\t1. to calculte V\t|\n");
    printf("|\t2. to calculte R\t|\n");
    printf("|\t3. to calculte I\t\n");
    printf("|\t4. Exit\t\t\t|\n");
    printf("---------------------------------\n");


}

void print_menu_item_33(void){
    printf("\n-----------Power equations -----------\n");
    printf("\n##### PRESS #####\n");
    printf("|\t1. to use P, V, I\t|\n");
    printf("|\t2. to use P, I, R\t|\n");
    printf("|\t3. to use P, V, R\t\n");
    printf("|\t4. Exit\t\t\t|\n");
    printf("---------------------------------\n");


}

void print_menu_item_44(void){
    printf("\n----------- Capacitance -----------\n");
    printf("\n##### PRESS #####\n");
    printf("|\t1. to calculte C\t|\n");
    printf("|\t2. to calculte Q\t|\n");
    printf("|\t3. to calculte V\t\n");
    printf("|\t4. Exit\t\t\t|\n");
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



//--------Ohms law in menu
void find_V(void){
    char buf[100];
   

    double I;
    double R;
    printf("\n Enter value for I\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        I  = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("V= %f\n", I); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for R\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        R = strtod(buf, NULL);
        printf("R1 = %f\n", R);
    }
    

    double V = I * R;// here a variable is created to store the value of the calculation of the values that where input previously

    printf("\n Vout= %f\n",V); //Prints value of V
}




void find_I(void){
    char buf[100];
   

    double V ;
    double R;
    printf("\n Enter value for V\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        V  = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("V= %f\n", V); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for R\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        R = strtod(buf, NULL);
        printf("R = %f\n", R);
    }
    

    double I= V/R;// here a variable is created to store the value of the calculation of the values that where input previously

    printf("\n I= %f\n",I); //Prints value 
}

void find_R(void){
    char buf[100];
   

    double V ;
    double I;
    printf("\n Enter value for V\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        V  = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("V = %f\n", V); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for I\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        I = strtod(buf, NULL);
        printf("R = %f\n", I);
    }
    

    double R= V/I;// here a variable is created to store the value of the calculation of the values that where input previously

    printf("\n I= %f\n",R); //Prints value 
}



void select_variable_OhmsLaw(int input) {
    switch (input) {
        case 1:find_V(); break;
        case 2:find_I (); break;
        case 3: find_R(); break;
        


        case 4: printf("Exiting program...\n"); exit(0);
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}

//power 
void select_equations_Power(int input) {
    switch (input) {
        case 1:PVI(); break;
        case 2:PIR(); break;
        case 3:PVR(); break;
        


        case 4: printf("Exiting program...\n"); exit(0);
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}

void PVI(void){// funtion that allows choosing the the variable that we want to calculate for the formula tha include PVI
printf("\nPress 1 to find P\n");
printf("\nPress 2 to find I\n");
printf("\nPress 3 to find V\n");
int input = get_user_input();

    switch (input)
    {
    case 1:find_P_PVI();break;
    case 2:find_I_PVI();break;
    case 3:find_V_PVI();break;
    case 4: printf("Exiting program...\n"); exit(0);

     default: printf("Invalid selection. Exiting...\n"); exit(1);
        
    
    
   
    }
   
}

void PIR(void){
printf("\nPress 1 to find P\n");
printf("\nPress 2 to find I\n");
printf("\nPress 3 to find R\n");
int input = get_user_input();

    switch (input)
    {
    case 1:find_P_PIR();break;
    case 2:find_I_PIR();break;
    case 3:find_R_PIR();break;
    case 4: printf("Exiting program...\n"); exit(0);

     default: printf("Invalid selection. Exiting...\n"); exit(1);
        

    
    }
}

void PVR(void){
printf("\nPress 1 to find P\n");
printf("\nPress 2 to find V\n");
printf("\nPress 3 to find R\n");
int input = get_user_input();

    switch (input)
    {
    case 1:find_P_PVR();break;
    case 2:find_V_PVI();break;
    case 3:find_R_PVI();break;
    case 4: printf("Exiting program...\n"); exit(0);

     default: printf("Invalid selection. Exiting...\n"); exit(1);
        

    
    }
}

//inside Power equation for PVI-----------------------------------------------------------


void find_P_PVI(void){
    char buf[100];
   

    double V ;
    double I;
    printf("\n Enter value for V\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        V  = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("V= %f\n", V); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for I\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        I = strtod(buf, NULL);
        printf("I = %f\n", I);
    }
    

    double P= V*I;// here a variable is created to store the value of the calculation of the values that where input previously

    printf("\n P= %f\n",P); //Prints value 
}

void find_I_PVI(void){
    char buf[100];
   

    double V ;
    double P;
    printf("\n Enter value for V\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        V  = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("V = %f\n", V); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for P\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        P = strtod(buf, NULL);
        printf("P = %f\n", P);
    }
    

    double I= P/V;// here a variable is created to store the value of the calculation of the values that where input previously

    printf("\n I= %f\n",I); //Prints value 
}

void find_V_PVI(void){
    char buf[100];
   

    double I ;
    double P;
    printf("\n Enter value for I\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        I  = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("I = %f\n", I); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for P\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        P = strtod(buf, NULL);
        printf("P = %f\n", P);
    }
    

    double V= P/I;// here a variable is created to store the value of the calculation of the values that where input previously

    printf("\n I= %f\n",I); //Prints value 
}


//POWER FOR PIR----------------------------------------------------------------------------------------------

void find_P_PIR(void){
    char buf[100];
   

    double R;
    double I;
    printf("\n Enter value for R\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        R = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("R= %f\n", R); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for I\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        I = strtod(buf, NULL);
        printf("I = %f\n", I);
    }
    
   
    double P= R*pow(2,I);// here a variable is created to store the value of the calculation of the values that where input previously

    printf("\n P= %f\n",P); //Prints value 
}


void find_R_PIR(void){
    char buf[100];
   

    double P;
    double I;
    printf("\n Enter value for P\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        P = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("P= %f\n", P); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for I\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        I = strtod(buf, NULL);
        printf("I = %f\n", I);
    }
    
   
    double R= P/(pow(2,I));// here a variable is created to store the value of the calculation of the values that where input previously

    printf("\n R= %f\n",R); //Prints value 
}



void find_I_PIR(void){
    char buf[100];
   

    double R;
    double P;
    printf("\n Enter value for R\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        R = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("R= %f\n", R); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for P\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        P = strtod(buf, NULL);
        printf("I = %f\n", P);
    }
    
   
    double I = sqrt(P / R);// here a variable is created to store the value of the calculation of the values that where input previously

    printf("\n I= %f\n",I); //Prints value 
}

//Power using PVR---------------------------------------

void find_P_PVR(void){
    char buf[100];
   

    double R;
    double V;
    printf("\n Enter value for R\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        R = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("R= %f\n", R); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for V\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        V= strtod(buf, NULL);
        printf("V = %f\n", V);
    }

    double P = pow(2,V)/R ;

     printf("\n P = %f\n",P); //Prints value 
}
//----------------------
void find_V_PVR(void){
    char buf[100];
   

    double R;
    double P;
    printf("\n Enter value for R\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        R = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("R= %f\n", R); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for P\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        P= strtod(buf, NULL);
        printf("V = %f\n", P);
    }

    double V =sqrt(P*R) ;

     printf("\n V = %f\n",V); //Prints value 
}

//--------------
void find_R_PVR(void){
    char buf[100];
   

    double P;
    double V;
    printf("\n Enter value for P\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        P = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("R= %f\n", P); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for V\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        V= strtod(buf, NULL);
        printf("V = %f\n", V);
    }

    double R = pow(2,V)/P ;

     printf("\n R = %f\n",R); //Prints value 
}





//// CAPACITANCE EQUATION FUNCTIONS

void find_C_CQV(void){
    char buf[100];
   

    double Q;
    double V;
    printf("\n Enter value for Q\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        Q  = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("Q= %f\n", Q); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for V\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        V = strtod(buf, NULL);
        printf("V = %f\n", V);
    }
    

    double C = Q/V;// here a variable is created to store the value of the calculation of the values that where input previously

    printf("\n C= %f\n",C); //Prints value
}



void find_Q_CQV(void){
    char buf[100];
   

    double C;
    double V;
    printf("\n Enter value for C\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        C  = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("C = %f\n", C); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for V\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        V = strtod(buf, NULL);
        printf("V = %f\n", V);
    }
    

    double Q = C*V;// here a variable is created to store the value of the calculation of the values that where input previously

    printf("\n Q = %f\n",Q); //Prints value

}

void find_V_CQV(void){
    char buf[100];
   

    double Q;
    double C;
    printf("\n Enter value for Q\n");
   if (fgets(buf, sizeof buf, stdin)) {  //if user enter a number fgets stores the number into buf as long as the characters are not more than 99
        Q  = strtod(buf, NULL); // here the string buf is converted int9 decimal and stored into the variable Vin
        printf("Q= %f\n", Q); // here the value of Vin is printed 
    }
    // same method used as the previous if statement
    printf("\n Enter value for C\n"); 
     if (fgets(buf, sizeof buf, stdin)) {
        C = strtod(buf, NULL);
        printf("V = %f\n", C);
    }
    

    double V = Q/C;// here a variable is created to store the value of the calculation of the values that where input previously

    printf("\n V= %f\n",V); //Prints value
}


void select_variable_capacitance(int input) {
    switch (input) {
        case 1:find_C_CQV(); break;
        case 2:find_Q_CQV(); break;
        case 3:find_V_CQV(); break;
        


        case 4: printf("Exiting program...\n"); exit(0);
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}



















