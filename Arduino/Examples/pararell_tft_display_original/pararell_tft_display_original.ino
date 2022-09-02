#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

LCDWIKI_KBV mylcd(ILI9486,40,38,39,-1,41); //model,cs,cd,wr,rd,reset

#define BLACK   0x0000
#define GREEN   0x07E0

// Offsets for slightly randomizing text position.
int x_offset = 0;
int y_offset = 0;

char* cdu1 = " WAYPT         0   D5/B1 ";
char* cdu2 = "                         ";
char* cdu3 = "+1     SP     INIT POSIT[";
char* cdu4 = "                    UNK  ";
char* cdu5 = "[EL:23     ******** DTOT[";
char* cdu6 = " NO CR                   ";
char* cdu7 = "[N34'35.367            ?1o";
char* cdu8 = "             WND ***/*** ";
char* cdu9 = "[E036'00.680         L/L^";
char* cdu10 ="[#              ]   P1/2 ";

void setup() 
{
  mylcd.Init_LCD();
  mylcd.Fill_Screen(BLACK); 
}

void loop() 
{
  mylcd.Set_Rotation(1); 
  mylcd.Set_Text_Mode(0);
  mylcd.Set_Text_colour(GREEN);
  mylcd.Set_Text_Back_colour(BLACK);
  mylcd.Set_Text_Size(3);
  mylcd.Print_String(cdu1, 0, y_coordinate_for_line(1));
  mylcd.Print_String(cdu2, 0, y_coordinate_for_line(2));
  mylcd.Print_String(cdu3, 0, y_coordinate_for_line(3));
  mylcd.Print_String(cdu4, 0, y_coordinate_for_line(4));
  mylcd.Print_String(cdu5, 0, y_coordinate_for_line(5));
  mylcd.Print_String(cdu6, 0, y_coordinate_for_line(6));
  mylcd.Print_String(cdu7, 0, y_coordinate_for_line(7));
  mylcd.Print_String(cdu8, 0, y_coordinate_for_line(8));
  mylcd.Print_String(cdu9, 0, y_coordinate_for_line(9));
  mylcd.Print_String(cdu10, 0, y_coordinate_for_line(10));
}

int y_coordinate_for_line(int line) {
  return 320 - (32 * (10 - (line - 1)));
}
