#include "Board.h"
#include "BulletinBoard.h"
#include <vcl.h>

BOARD :: BOARD(){
head = NULL;
count = 0;}

void BOARD :: Add (bool category, char * section, char * text, char * date, char * tnumber){
Board *s = head;
bool f = 0;
if (head != NULL)
while (s != NULL){
if (strcmp(s->Text, text) == 0)
{f = 1;
 break;}
  s = s -> next;
}
if (f == 0){
Board * t = new Board;
Board * h = head;
t->Category = category;
strcpy(t -> Section, section);
strcpy(t -> Text, text);
strcpy(t -> Date, date);
strcpy(t -> TNumber, tnumber);
t -> next = NULL;
if (head == 0)
{head = t;}
else
{while (h -> next != NULL)
  {h = h -> next;}
 h -> next = t;
}
count ++; }
}

void BOARD :: Add (Board b){
Board * s = head;
bool f = 0;
while (s != NULL){
if (strcmp(s->Text, b.Text) == 0)
{f = 1;
 break;}
s = s -> next;}
if (f == 0){
Board * t = new Board;
Board * h = head;
t->Category = b.Category;
strcpy(t -> Section, b.Section);
strcpy(t -> Text, b.Text);
strcpy(t -> Date, b.Date);
strcpy(t -> TNumber, b.TNumber);
t -> next = NULL;
if (head == 0)
{head = t;}
else
{while (h -> next != NULL)
  {h = h -> next;}
 h -> next = t;
}
count ++;}
}

void BOARD :: CreateBoard(char * File_Name){
bool category;
char str0[2];
ifstream fromfile;
fromfile.open(File_Name);
Board obj;
while (!fromfile.eof()){
fromfile.getline(str0, 2, '\n');
if (fromfile.eof())
 {break;}
if (strcmp(str0,"0")==0)
obj.Category = 0;
else
obj.Category = 1;
fromfile.getline(obj.Section, STN+1, '\n');
fromfile.getline(obj.Text, TEXT, '\n');
fromfile.getline(obj.Date, DAT+1, '\n');
fromfile.getline(obj.TNumber, TN+1, '\n');
Add(obj);
}
fromfile.close();
obj.D_Board();
}


void BOARD :: CreateBoardM(){
char str3[DAT], str4[TN];
const bool category = 1;
for (int i = 0; i < Form1->Memo1->Lines->Count; i++){
char *str = new char[TEXT];
char *str2 = new char[TEXT];
strcpy(str2, Form1->Memo1->Lines->Strings[i].c_str());
strcpy(str, str2);
i++;
while (!atoi(Form1->Memo1->Lines->Strings[i].c_str()))
{strcpy(str2, Form1->Memo1->Lines->Strings[i].c_str());
 strcat(str,str2);
 i++;
}
while (!atoi(Form1->Memo1->Lines->Strings[i].c_str()));
strcpy(str3, Form1->Memo1->Lines->Strings[i].c_str());
i++;
strcpy(str4, Form1->Memo1->Lines->Strings[i].c_str());
i++;
Add(category, "a", str, str3, str4);
delete str2;
delete str;
}
}


void BOARD :: Print(bool category, char *list){
Board * t = head;
while (t != NULL)
{if ((strncmp(t->Section, list, 2 )== 0) && (t->Category == category))
  {Form1 -> Memo1->Lines->Add (t->Text);
   Form1 -> Memo1->Lines->Add (t->Date);
   Form1 -> Memo1->Lines->Add (t->TNumber);
   Form1 -> Memo1->Lines->Add (" ");
  }
 t = t -> next;
}
}

void BOARD :: Print(){
Board * t = head;
while (t != NULL)
{
Form1 -> Memo1->Lines->Add (t->Text);
Form1 -> Memo1->Lines->Add (t->Date);
Form1 -> Memo1->Lines->Add (t->TNumber);
Form1 -> Memo1->Lines->Add (" ");
t = t -> next;
}
}

void BOARD :: Print_one(Board *one){
Board *b = head;
while (b!=NULL)
{if (b == one)
 break;
 b= b->next;
}
Form1 -> Memo1->Lines->Add (b->Text);
Form1 -> Memo1->Lines->Add (b->Date);
Form1 -> Memo1->Lines->Add (b->TNumber);
Form1 -> Memo1->Lines->Add (" ");
}   


void BOARD :: D_BOARD(){
Board *temp;
while (head != NULL)
{ temp = head;
  head =  head -> next;
  temp->D_Board();
  count --;
 }
}


void BOARD :: Search(BOARD A, char *look){         //z-функция

int len, lens, i, right, left;
signed int min;
len = strlen(look);
Board *t = A.head;
while(t != NULL)
{  char *s = new char[TEXT+len+1];
  i = 0;
  min = 0;
  lens = 0;
  strncpy(s, look, len);
 strcat(s, "#");
 strcat(s, t->Text);

 lens = strlen(s);
 int * mas = new int [lens];
 for (i = 0; i < lens; i ++)
 {mas[i]= 0; }

 mas[0] = lens;

 right = 0, left = 0;
 for (i = 1; i < lens; i ++)
 { if(i <= right)
   {if ((right - i + 1) < (mas[i - left]))
      min = right - i + 1;
    else
      min = mas[i - left];
    mas[i] = min;
    }
   while ((i + mas[i] < lens) && (strnicmp(s+mas[i],s + i + mas[i], 1)==0))
     { mas[i]++;}
   if (i + mas[i] - 1 > right)
     {left = i;
      right = i + mas[i] - 1;
  }
  }


 /*String result;
 for (i = 0; i < lens; i ++)
 result += IntToStr(mas[i]);
 Form1 -> Memo1->Lines->Add(result);    */

 for (i = len; i <= lens; i ++)
 if (mas[i] == len)
 {Add(t);
 break;
 }
 delete s;
 delete mas;
 t = t->next;
}
}


void BOARD :: Sort(BOARD A){             //Простой выбор
//int n = 0, i;
//Board *temp, *max;
//BOARD R;
int i_year_1, i_month_1, i_day_1, i_year_2, i_month_2, i_day_2;

char *year1= new char [5];
char *month1 = new char [3];
char *day1= new char [3];

char *year2= new char [5];
char *month2 = new char [3];
char *day2= new char [3];

Board *temp, *min, *t = A.head, *p, *temp2;

 while (t != NULL)
 {  p = A.head;
  strncpy(year1, t->Date+6, 4);
    i_year_1 = atoi(year1);
    strncpy(month1, t-> Date+3, 2);
    i_month_1 = atoi(month1);
    strncpy(day1, t-> Date, 2);
    i_day_1 = atoi(day1);

      min = t;
   min -> next = t -> next;
   min -> Category = t -> Category;
   strcpy(min -> Section, t -> Section);
   strcpy(min -> Text, t -> Text);
   strcpy(min -> Date, t -> Date);
   strcpy(min -> TNumber, t -> TNumber);

   while (p != NULL)
   {
   strncpy(year2, p->Date+6, 4);
   i_year_2 = atoi(year2);
   strncpy(month2, p-> Date+3, 2);
   i_month_2 = atoi(month2);
   strncpy(day2, p-> Date, 2);
   i_day_2 = atoi(day2);

   if (first_after (i_day_2, i_month_2, i_year_2, i_day_1, i_month_1, i_year_1) == true)
   { min = p;
   min -> next = p -> next;
   min -> Category = p -> Category;
   strcpy(min -> Section, p -> Section);
   strcpy(min -> Text, p -> Text);
   strcpy(min -> Date, p -> Date);
   strcpy(min -> TNumber, p -> TNumber);
   i_day_1 = i_day_2;
   i_month_1 = i_month_2;
   i_year_1 = i_year_2;
   }
        p = p -> next;
   }

   Add(min);
   A.DEL(min);

     if (min == t)
    t = t -> next;

  }
  delete year1;
  delete month1;
  delete day1;
  delete year2;
  delete month2;
  delete day2;

}


bool BOARD :: first_after( int d1, int m1, int y1, int d2, int m2, int y2){
bool rez = 0;
if (y1 > y2)
 rez = true;
else
 if ( y2 > y1)
  rez = false;
 else
  if (y1 == y2)
   {if (m1 > m2)
     rez = true;
    else
     if (m2 > m1)
       rez = false;
     else
       if (m1 == m2)
        {if (d1 > d2)
          rez = true;
         else
          rez= false;
         }
     }
return rez;
}


void BOARD :: DEL(Board *d) {
Board *t = head, *temp;
if (d == head)
head = head->next;
else{
while (t != NULL){
if (t -> next == d)
{
break;}
else
t = t -> next;
}
if (t -> next != NULL)
 t -> next = t -> next -> next;
else
 t = NULL; }
count--;
}

void BOARD :: Add (Board *b){
Board * s = head;
bool f = 0;
while (s != NULL){
if (strcmp(s->Text, b->Text) == 0)
{f = 1;
 break;}
s = s -> next;}
if (f == 0){
Board * t = new Board;
Board * h = head;
t->Category = b->Category;
strcpy(t -> Section, b -> Section);
strcpy(t -> Text, b -> Text);
strcpy(t -> Date, b -> Date);
strcpy(t -> TNumber, b -> TNumber);
t -> next = NULL;
if (head == 0)
{head = t;}
else
{while (h -> next != NULL)
  {h = h -> next;}
 h -> next = t;
}
count ++;}
}





