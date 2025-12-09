#ifndef FUNCS_H
#define FUNCS_H

void main_menu(void);
void clear_input_buffer(void);
int  get_user_input(void);
void select_menu_item(int input);
void print_main_menu(void);
void go_back_to_main(void);

//menu 

void menu_item_1(void); 
void menu_item_2(void); 
void menu_item_3(void); 
void menu_item_4(void); 
void menu_item_5(void);

//menu inside menu
void print_menu_item_11(void);
void print_menu_item_22(void);
void print_menu_item_33(void);
void print_menu_item_44(void);


//pontential divider functions
void find_Vout(void);
void find_Vin(void);
void find_R2(void);
void find_R1(void);

void select_variable_PotentialDivider(int input);
 
//Ohms law functions
void find_V(void);
void find_I(void);
void find_R(void);

void select_variable_OhmsLaw(int input);

//Power
void select_equations_Power(int input);
void PVI(void);
void PIR(void);
void PVR(void);

void find_P_PVI(void);
void find_I_PVI(void);
void find_V_PVI(void);

void find_P_PIR(void);
void find_R_PIR(void);
void find_I_PIR(void);

void find_P_PVR(void);
void find_V_PVR(void);
void find_R_PVR(void);

//capacitance
void find_C_CQV(void);
void find_Q_CQV(void);
void find_V_CQV(void);
void select_variable_capacitance(int input);

//search engine
void search_engine(void);
#endif