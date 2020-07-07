//---------------------------------------------------------------------------

#include <vcl.h>
#include <dstring>
#include <string>
#include <fstream.h>
#pragma hdrstop
#include "Board.h"
#include "Ad.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button1Click(TObject *Sender)
{  if ((!CheckBox1->Checked && !CheckBox2->Checked) || (CheckBox1->Checked && CheckBox2->Checked) || Edit1->Text.c_str()==0 || ListBox1->ItemIndex==-1)
ShowMessage("Заполните все поля");
else
if(strlen(Edit2->Text.c_str())!=10)
ShowMessage("Дата введена неверно");
else
if(strlen(Edit3->Text.c_str())!=11)
ShowMessage("Номер телефона введен неверно");
else{
Board obj;
if( OpenDialog1-> Execute()){
ofstream tofile(OpenDialog1->FileName.c_str(), ios::app);
if (CheckBox1->Checked)
tofile<<'0'<<'\n';
else
if (CheckBox2->Checked)
tofile<<'1'<<'\n';

strcpy(obj.Section, ListBox1->Items->Strings[ListBox1->ItemIndex].c_str());
tofile<<obj.Section<<'\n';
strcpy(obj.Text, Edit1->Text.c_str());
tofile<<obj.Text<<'\n';
strcpy(obj.Date, Edit2->Text.c_str());
tofile<<obj.Date<<'\n';
strcpy(obj.TNumber, Edit3->Text.c_str());
tofile<<obj.TNumber<<'\n';
tofile.close(); }
}
Edit1->Clear();
Edit2->Clear();
Edit3->Clear();
CheckBox1->Checked=false;
CheckBox2->Checked=false;
CheckBox1->Enabled=true;
CheckBox2->Enabled=true;
Form2 -> Visible = false;
}
//----------------------------------------------------------------------------

void __fastcall TForm2::CheckBox1Click(TObject *Sender)
{ if (CheckBox1->Checked)
CheckBox2->Enabled=false;
if (!CheckBox1->Checked)
CheckBox2->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::CheckBox2Click(TObject *Sender)
{
 if (CheckBox2->Checked)
CheckBox1->Enabled=false;
if (!CheckBox2->Checked)
CheckBox1->Enabled=true;
}
//---------------------------------------------------------------------------


