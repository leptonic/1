unit Unit2;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, DBCtrls, DB, ADODB;
type
  TForm2 = class(TForm)

    Edit1: TEdit;
    Button1: TButton;
    Edit2: TEdit;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;
  ie:integer;

implementation

uses Unit1;

{$R *.dfm}

procedure TForm2.Button1Click(Sender: TObject);
function GB2Unicode(GB:string):string;
var
s: string;
  i, j, k: integer;
  a: array [1..1000] of char;
begin
  s:='';
  StringToWideChar(GB, @(a[1]), 500);
  i:=1;
  while ((a[i]<>#0) or (a[i+1]<>#0)) do begin
  j:=Integer(a[i]); k:=Integer(a[i+1]);
  s:=s+Copy(Format('%X ',[k*$100+j+$10000]) ,2,4);
  i:=i+2;
  end;
  Result:=s;
end;


  var
  i : integer;
  s31 : string;
begin
  s31 := '$' + GB2Unicode(edit1.text);
   i := StrToInt(s31);
  ie:=i;
 edit2.Text:= inttostr(ie);
 DBText1.Field.AsString :=edit2.text;
  form1.show;
  close ;
 end;


end.
