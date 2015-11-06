unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls,StrUtils, DBCtrls, DB, ADODB;

type
  TForm1 = class(TForm)
    Edit1: TEdit;
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    GroupBox3: TGroupBox;
    GroupBox4: TGroupBox;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    Button8: TButton;
    Button9: TButton;
    Button10: TButton;
    Button11: TButton;
    Button12: TButton;
    Button13: TButton;
    Button14: TButton;
    Button15: TButton;
    Button16: TButton;
    Button17: TButton;
    Button18: TButton;
    Button19: TButton;
    Button20: TButton;
    Button21: TButton;
    Button22: TButton;
    Button23: TButton;
    Button24: TButton;
    Button25: TButton;
    Button26: TButton;
    Button27: TButton;
    Button28: TButton;
    Button29: TButton;
    Button30: TButton;
    Button31: TButton;
    Button32: TButton;
    Button33: TButton;
    Button34: TButton;
    Button35: TButton;
    Button36: TButton;
    Button37: TButton;
    Button38: TButton;
    Button39: TButton;
    Button40: TButton;
    Button41: TButton;
    Memo1: TMemo;
    Memo3: TMemo;
    Memo4: TMemo;
    Memo5: TMemo;
    Memo6: TMemo;
    Memo7: TMemo;
    Memo8: TMemo;
    Memo9: TMemo;
    Memo2: TMemo;
    Memo10: TMemo;
    Button42: TButton;
    Edit2: TEdit;
    ADOConnection1: TADOConnection;
    ADOQuery1: TADOQuery;
    DataSource1: TDataSource;
    DBText1: TDBText;
    Button1: TButton;
    procedure FormCreate(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button12Click(Sender: TObject);
    procedure Button22Click(Sender: TObject);
    procedure Button32Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button8Click(Sender: TObject);
    procedure Button9Click(Sender: TObject);
    procedure Button10Click(Sender: TObject);
    procedure Button11Click(Sender: TObject);
    procedure Button13Click(Sender: TObject);
    procedure Button14Click(Sender: TObject);
    procedure Button15Click(Sender: TObject);
    procedure Button16Click(Sender: TObject);
    procedure Button17Click(Sender: TObject);
    procedure Button18Click(Sender: TObject);
    procedure Button19Click(Sender: TObject);
    procedure Button20Click(Sender: TObject);
    procedure Button21Click(Sender: TObject);
    procedure Button23Click(Sender: TObject);
    procedure Button24Click(Sender: TObject);
    procedure Button25Click(Sender: TObject);
    procedure Button26Click(Sender: TObject);
    procedure Button27Click(Sender: TObject);
    procedure Button28Click(Sender: TObject);
    procedure Button29Click(Sender: TObject);
    procedure Button30Click(Sender: TObject);
    procedure Button31Click(Sender: TObject);
    procedure Button33Click(Sender: TObject);
    procedure Button34Click(Sender: TObject);
    procedure Button35Click(Sender: TObject);
    procedure Button36Click(Sender: TObject);
    procedure Button37Click(Sender: TObject);
    procedure Button38Click(Sender: TObject);
    procedure Button39Click(Sender: TObject);
    procedure Button40Click(Sender: TObject);
    procedure Button41Click(Sender: TObject);
    procedure Button42Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  a:string;
  b:string;
  c:string;
  d:string;
  adfa:array[1..40] of integer;  {40个随机数组}
  stkey:integer;
  implementation



{$R *.dfm}

procedure TForm1.FormCreate(Sender: TObject);
  function rana():integer;
var ran:integer;
begin
    Randomize;
ran:=Random(4)*10000+Random(9)*1000+Random(9)*100+Random(9)*10+Random(9);
if ran>40869 then ran:=ran-20928
else if ran<19968 then ran:=ran+19968
else ran:=ran;
  result:=ran;
end;
var


i1: integer;

 begin               //初始化常量定义区;
  a:='777';
  b:='777';
  c:='777';
  d:='777';
  stkey:=strtoint(DBText1.Caption);           //密码;

    begin
    for i1:=1 to 40 do

    adfa[i1]:=rana();

    end;
    adfa[random(39)+1]:=stkey;
    Button2.caption :=widechar(adfa[1]);
    Button3.caption :=widechar(adfa[2]);
    Button4.caption :=widechar(adfa[3]);
    Button5.caption :=widechar(adfa[4]);
    Button6.caption :=widechar(adfa[5]);
    Button7.caption :=widechar(adfa[6]);
    Button8.caption :=widechar(adfa[7]);
    Button9.caption :=widechar(adfa[8]);
    Button10.caption :=widechar(adfa[9]);
    Button11.caption :=widechar(adfa[10]);
    Button12.caption :=widechar(adfa[11]);
    Button13.caption :=widechar(adfa[12]);
    Button14.caption :=widechar(adfa[13]);
    Button15.caption :=widechar(adfa[14]);
    Button16.caption :=widechar(adfa[15]);
    Button17.caption :=widechar(adfa[16]);
    Button18.caption :=widechar(adfa[17]);
    Button19.caption :=widechar(adfa[18]);
    Button20.caption :=widechar(adfa[19]);
    Button21.caption :=widechar(adfa[20]);
    Button22.caption :=widechar(adfa[21]);
    Button23.caption :=widechar(adfa[22]);
    Button24.caption :=widechar(adfa[23]);
    Button25.caption :=widechar(adfa[24]);
    Button26.caption :=widechar(adfa[25]);
    Button27.caption :=widechar(adfa[26]);
    Button28.caption :=widechar(adfa[27]);
    Button29.caption :=widechar(adfa[28]);
    Button30.caption :=widechar(adfa[29]);
    Button31.caption :=widechar(adfa[30]);
    Button32.caption :=widechar(adfa[31]);
    Button33.caption :=widechar(adfa[32]);
    Button34.caption :=widechar(adfa[33]);
    Button35.caption :=widechar(adfa[34]);
    Button36.caption :=widechar(adfa[35]);
    Button37.caption :=widechar(adfa[36]);
    Button38.caption :=widechar(adfa[37]);
    Button39.caption :=widechar(adfa[38]);
    Button40.caption :=widechar(adfa[39]);
    Button41.caption :=widechar(adfa[40]);



end;

procedure TForm1.Button2Click(Sender: TObject);
begin
a:='1';
GroupBox4.Enabled :=false;
end;

procedure TForm1.Button12Click(Sender: TObject);
begin
b:='1';
end;

procedure TForm1.Button22Click(Sender: TObject);
begin
c:='1';
end;

procedure TForm1.Button32Click(Sender: TObject);
begin
d:='1';
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
a:='2';
GroupBox4.Enabled :=false;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
a:='3';
GroupBox4.Enabled :=false;
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
a:='4';
GroupBox4.Enabled :=false;
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
a:='5';
GroupBox4.Enabled :=false;
end;

procedure TForm1.Button7Click(Sender: TObject);
begin
a:='6';
GroupBox4.Enabled :=false;
end;

procedure TForm1.Button8Click(Sender: TObject);
begin
a:='7';GroupBox4.Enabled :=false;
end;

procedure TForm1.Button9Click(Sender: TObject);
begin
a:='8';GroupBox4.Enabled :=false;
end;

procedure TForm1.Button10Click(Sender: TObject);
begin
a:='9';GroupBox4.Enabled :=false;
end;

procedure TForm1.Button11Click(Sender: TObject);
begin
a:='0';GroupBox4.Enabled :=false;
end;

procedure TForm1.Button13Click(Sender: TObject);
begin
b:='2';
end;

procedure TForm1.Button14Click(Sender: TObject);
begin
b:='3';
end;

procedure TForm1.Button15Click(Sender: TObject);
begin
b:='4';
end;

procedure TForm1.Button16Click(Sender: TObject);
begin
b:='5';
end;

procedure TForm1.Button17Click(Sender: TObject);
begin
b:='6';
end;

procedure TForm1.Button18Click(Sender: TObject);
begin
b:='7';
end;

procedure TForm1.Button19Click(Sender: TObject);
begin
b:='8';
end;

procedure TForm1.Button20Click(Sender: TObject);
begin
b:='9';
end;

procedure TForm1.Button21Click(Sender: TObject);
begin
b:='0';
end;

procedure TForm1.Button23Click(Sender: TObject);
begin
c:='2';
end;

procedure TForm1.Button24Click(Sender: TObject);
begin
c:='3';
end;

procedure TForm1.Button25Click(Sender: TObject);
begin
c:='4';
end;

procedure TForm1.Button26Click(Sender: TObject);
begin
c:='5';
end;

procedure TForm1.Button27Click(Sender: TObject);
begin
c:='6';
end;

procedure TForm1.Button28Click(Sender: TObject);
begin
c:='7';
end;

procedure TForm1.Button29Click(Sender: TObject);
begin
c:='8';
end;

procedure TForm1.Button30Click(Sender: TObject);
begin
c:='9';
end;

procedure TForm1.Button31Click(Sender: TObject);
begin
c:='0';
end;

procedure TForm1.Button33Click(Sender: TObject);
begin
d:='2';
end;

procedure TForm1.Button34Click(Sender: TObject);
begin
d:='3';
end;

procedure TForm1.Button35Click(Sender: TObject);
begin
d:='4';
end;

procedure TForm1.Button36Click(Sender: TObject);
begin
d:='5';
end;

procedure TForm1.Button37Click(Sender: TObject);
begin
d:='6';
end;

procedure TForm1.Button38Click(Sender: TObject);
begin
d:='7';
end;

procedure TForm1.Button39Click(Sender: TObject);
begin
d:='8';
end;

procedure TForm1.Button40Click(Sender: TObject);
begin
d:='9';
end;

procedure TForm1.Button41Click(Sender: TObject);
begin
d:='0';
end;

procedure TForm1.Button42Click(Sender: TObject);     //数值验证部分;
var
id1:integer;
id2:integer;
id3:integer;
id4:integer;
ia1:integer;
ia2:integer;
ia3:integer;
ia4:integer;

begin
 if edit1.text ='0'then edit1.text:=a+b+c+d;
 id1:=strtoint(copy(edit1.Text ,1,1));                    //抽取数值;
 id2:=strtoint(copy(edit1.Text ,2,1));
 id3:=strtoint(copy(edit1.Text ,3,1));
 id4:=strtoint(copy(edit1.Text ,4,1));
if id1=0 then begin ia1:=adfa[10]; end
  else begin
  ia1:=adfa[id1];
  end;
if id2=0 then begin ia2:=adfa[20]; end
  else begin
  ia2:=adfa[10+id2];
  end;
if id3=0 then begin ia3:=adfa[30]; end
  else begin
  ia3:=adfa[20+id3];
  end;
if id4=0 then begin ia4:=adfa[40]; end
  else begin
  ia4:=adfa[30+id4];
  end;
if (ia1=stkey)or(ia2=stkey)or(ia3=stkey)or(ia4=stkey)
then begin showmessage('密码正确'); end
else begin edit2.text :='密码错误，请重新输入'; end;

end;

procedure TForm1.Button1Click(Sender: TObject);
begin
showmessage('首先定义好自己的密码关键字（用“定义关键字.exe”），依次填入每一位数字，关键字所在的行要填关键字所对应的数字，其他行任意填写；或者直接点击关键字按键并且随意点击其他位按键，注意每一位只能点一次');
end;

end.





