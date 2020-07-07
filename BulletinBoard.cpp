//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <fstream.h>
#include "Board.h"
#include "Ad.h"
#include "BulletinBoard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

const char * LBox[11]={"Рубрики:", "Другое", "Животные", "Книги", "Материалы", "Недвижимость",
"Одежда", "Спорт", "Техника", "Транспорт", "Увлечения"};
char *File_Name;
 BOARD A, F;
 Board * t;

 __fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
for(int i = 0; i <= 10; i ++)
ListBox1->Items->Add(LBox[i]);


File_Name = new char [TEXT];
if( Form1->OpenDialog1-> Execute())
strcpy (File_Name, Form1->OpenDialog1->FileName.c_str());

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
Form2->Visible = true;
for(int i = 1; i <= 10; i ++)
Form2->ListBox1->Items->Add(LBox[i]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{ Memo1-> Height = 441;
BitBtn1->Visible=false;
BitBtn2->Visible=false;
A.CreateBoard(File_Name);
char *str = new char[10];
bool categor;
Memo1->Lines->Clear();

if (RadioButton1->Checked)
 {categor = 1;}
else
{if (RadioButton2->Checked)
 {categor = 0;
 }
}

strcpy(str, ListBox1->Items->Strings[ListBox1->ItemIndex].c_str());
A.Print(categor, str);

if (Memo1->Lines->Count==0)
Memo1->Lines->Add("Упс.. У нас такого нет(");
else
{Button4->Visible=true;
Button5->Visible=true;
Button7->Visible=true; }
delete str;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
if (ListBox1->ItemIndex)
if( RadioButton1->Checked || RadioButton2->Checked)
Button2->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{ Memo1-> Height = 441;
BitBtn1->Visible=false;
BitBtn2->Visible=false;
A.CreateBoard(File_Name);
  Memo1->Lines->Clear();
  char *str = new char[20];
  strcpy(str, Edit1->Text.c_str());
  if (strlen(str)==0)
   Memo1->Lines->Add("Введите слово для поиска");
  else
   {BOARD C;
    C.Search(A, str);
    C.Print();
    C.D_BOARD();
   }

delete str;
if (Memo1->Lines->Count==0)
Memo1->Lines->Add("Ничего не найдено");
else
{Button4->Visible=true;
Button5->Visible=true;
Button7->Visible=true; }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{Memo1-> Height = 441;
BitBtn1->Visible=false;
BitBtn2->Visible=false;

 BOARD D, E;
 D.CreateBoardM();
 E.Sort(D);
 Memo1->Lines->Clear();
 E.Print();
  E.D_BOARD();
  D.D_BOARD();
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{  Memo1-> Height = 441;
BitBtn1->Visible=false;
BitBtn2->Visible=false;
 Memo1->Lines->Clear();
 Button4->Visible=false;
Button5->Visible=false;
Button7->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{Memo1-> Height = 441;
BitBtn1->Visible=false;
BitBtn2->Visible=false;
BOARD B;
B.CreateBoard(File_Name);
Memo1->Lines->Clear();
B.Print();
Button4->Visible=true;
Button5->Visible=true;
Button7->Visible=true;
 B.D_BOARD();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{ F.D_BOARD();
 F.CreateBoardM();
 Memo1->Lines->Clear();
  Memo1-> Height = 300;
 t = F.head;
 if (t->next !=NULL)
  BitBtn1->Visible = true;
 F.Print_one(t);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
Memo1->Lines->Clear();
BitBtn2->Visible = true;
t = t->next;
F.Print_one(t);
if (t->next == NULL)
BitBtn1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{  Memo1->Lines->Clear();
BitBtn1->Visible = true;
 Board * p = F.head;
 while (p->next != t)
 p=p->next;
 t=p;
 F.Print_one(p);
 if (t == F.head)
 BitBtn2->Visible = false;

}
//---------------------------------------------------------------------------

