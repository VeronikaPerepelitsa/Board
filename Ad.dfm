object Form2: TForm2
  Left = 360
  Top = 124
  Width = 700
  Height = 368
  Cursor = crArrow
  Caption = #1055#1086#1076#1072#1095#1072' '#1086#1073#1098#1103#1074#1083#1077#1085#1080#1103
  Color = clGradientActiveCaption
  Constraints.MaxHeight = 368
  Constraints.MaxWidth = 700
  Constraints.MinHeight = 368
  Constraints.MinWidth = 700
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Bookman Old Style'
  Font.Style = [fsItalic]
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 23
  object Label1: TLabel
    Left = 24
    Top = 124
    Width = 182
    Height = 23
    Caption = #1058#1077#1082#1089#1090' '#1086#1073#1098#1103#1074#1083#1077#1085#1080#1103':'
  end
  object Label2: TLabel
    Left = 26
    Top = 170
    Width = 261
    Height = 23
    Caption = #1044#1072#1090#1072' '#1087#1086#1076#1072#1095#1080' (30.02.2020):'
  end
  object Label3: TLabel
    Left = 24
    Top = 211
    Width = 230
    Height = 23
    Caption = #1050#1086#1085#1090#1072#1082#1090#1085#1099#1081' '#1090#1077#1083#1077#1092#1086#1085':'
  end
  object Label4: TLabel
    Left = 26
    Top = 9
    Width = 85
    Height = 23
    Caption = #1056#1091#1073#1088#1080#1082#1072':'
  end
  object Label5: TLabel
    Left = 352
    Top = 8
    Width = 110
    Height = 23
    Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103':'
  end
  object Edit1: TEdit
    Left = 221
    Top = 119
    Width = 428
    Height = 31
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 304
    Top = 164
    Width = 345
    Height = 31
    TabOrder = 1
  end
  object Button1: TButton
    Left = 286
    Top = 256
    Width = 113
    Height = 49
    Caption = #1043#1086#1090#1086#1074#1086'!'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Bookman Old Style'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object ListBox1: TListBox
    Left = 128
    Top = 8
    Width = 179
    Height = 97
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Bookman Old Style'
    Font.Style = [fsBold, fsItalic]
    ItemHeight = 19
    ParentFont = False
    TabOrder = 3
  end
  object Edit3: TEdit
    Left = 304
    Top = 205
    Width = 346
    Height = 31
    TabOrder = 4
    Text = '8'
  end
  object CheckBox1: TCheckBox
    Left = 480
    Top = 11
    Width = 97
    Height = 21
    Cursor = crHandPoint
    Caption = #1055#1088#1086#1076#1072#1084
    TabOrder = 5
    OnClick = CheckBox1Click
  end
  object CheckBox2: TCheckBox
    Left = 480
    Top = 36
    Width = 95
    Height = 21
    Cursor = crHandPoint
    Caption = #1050#1091#1087#1083#1102
    TabOrder = 6
    OnClick = CheckBox2Click
  end
  object OpenDialog1: TOpenDialog
    Left = 10
    Top = 295
  end
end
