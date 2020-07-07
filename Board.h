#include <iostream.h>
#include <fstream.h>
#include <string.h>

#pragma hdrstop
const int STN = 15, TEXT = 100, DAT = 10, TN = 11;

struct Board {
bool Category;    //0 - продам, 1 - куплю
char * Section;
char * Text;
char * Date;
char * TNumber;

Board * next;

Board(){
Section = new char [STN];
Text = new char[TEXT];
Date = new char [DAT];
TNumber = new char [TN];
}

void D_Board(){
delete[] Section;
delete[] Text;
delete[] Date;
delete[] TNumber;
}


};

class BOARD{
public:
Board * head;
int count;

BOARD();
void D_BOARD();
void Add (bool category, char * section, char * text, char * date, char * tnumber);
void Add (Board *b);
void Add (Board b);
void CreateBoard(char * File_Name);
void CreateBoardM();
void Print(bool category, char *list);
void Print();
void Print_one(Board *one);
void Search(BOARD A, char *look);
void Sort(BOARD B);
bool first_after(int d1, int d2, int m1, int m2, int y1, int y2);
void DEL(Board *d);
};


        

