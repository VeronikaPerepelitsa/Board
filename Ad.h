//---------------------------------------------------------------------------

#ifndef AdH
#define AdH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit1;
        TLabel *Label3;
        TEdit *Edit2;
        TButton *Button1;
        TLabel *Label4;
        TListBox *ListBox1;
        TEdit *Edit3;
        TOpenDialog *OpenDialog1;
        TLabel *Label5;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
                
        
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
