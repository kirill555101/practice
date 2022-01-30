Unit Unit3;

interface

uses System, System.Drawing, System.Windows.Forms,mine;

type
  Form1 = class(Form)
    procedure button1_Click(sender: Object; e: EventArgs);
    procedure button2_Click(sender: Object; e: EventArgs);
    procedure button3_Click(sender: Object; e: EventArgs);
    procedure maskedTextBox1_MaskInputRejected(sender: Object; e: MaskInputRejectedEventArgs);
    procedure label4_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit3.Form1.resources}
    button2: Button;
    button1: Button;
    maskedTextBox4: MaskedTextBox;
    label4: &Label;
    maskedTextBox3: MaskedTextBox;
    label3: &Label;
    maskedTextBox2: MaskedTextBox;
    label2: &Label;
    maskedTextBox1: MaskedTextBox;
    button3: Button;
    label1: &Label;
    {$include Unit3.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
    end;
  end;

implementation
uses unit1;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
var
  service1:string;
  days1:integer;
  surname1:string;
  price1:integer;
  s:string;
  pr_file:Pricelist_File;
  i,n,j:integer;
  key:boolean:=false;
begin
  if (maskedtextbox1.Text='') or (maskedtextbox2.Text='') or (maskedtextbox3.Text='') or (maskedtextbox4.Text='') then exit;
  service1:=maskedtextbox1.Text;
  surname1:=maskedtextbox2.Text;
  s:=maskedtextbox3.Text;
  for i:=1 to length(s) do
    if (s[i] in ['a'..'z']) or (s[i] in ['A'..'Z']) or (s[i] in ['а'..'я']) or (s[i] in ['А'..'Я']) then begin
      messageBox.Show('Неверная форма записи срока выполнения. Он должна включать только цифры!','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.Error);
      exit;
    end;
  s:=maskedtextbox4.Text;
  for i:=1 to length(s) do
    if (s[i] in ['a'..'z']) or (s[i] in ['A'..'Z']) or (s[i] in ['а'..'я']) or (s[i] in ['А'..'Я']) then begin
      messageBox.Show('Неверная форма записи стоимости. Она должна включать только цифры!','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.Error);
      exit;
    end;
  days1:=strtoint(maskedtextbox3.Text); 
  price1 := strtoint(maskedtextbox4.Text);
  with pr_file do begin
    service:=service1;
    days:=days1;
    surname:=surname1;
    price:=price1;
  end;
  assign(f,'file.dat');
  reset(f);
  n:=input();
  for i:=1 to n do begin
    if lists[i].Is_Equally(pr_file) then begin
      key:=true;
      for j:=i to n-1 do
        lists[j]:=lists[j+1];
      lists[n]:=nil;
      n-=1;
      break;
    end;
  end;
  if key then
    messageBox.Show('Данные успешно удалены','Информация',MessageBoxButtons.OK,MessageBoxIcon.information)
  else begin
    messageBox.Show('Данные не найдены','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.error);
    exit;
  end;
  assign(f,'file.dat');
  rewrite(f);
  for i:=1 to n do begin
    with pr_file do begin
      service:=lists[i].Get_Service;
      days:=lists[i].Get_Days;
      surname:=lists[i].Get_Surname;
      price:=lists[i].Get_Price
    end;
    write(f,pr_file);
    lists[i]:=nil;
  end;
  closefile(f);
  maskedtextbox1.Text:='';
  maskedtextbox2.Text:='';
  maskedtextbox3.Text:='';
  maskedtextbox4.Text:='';
end;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
begin
  form(new unit1.form1).Show;
  self.Close;
end;

procedure Form1.button3_Click(sender: Object; e: EventArgs);
begin
  assign(f,'file.dat');
  rewrite(f);
  closefile(f);
  messageBox.Show('Данные успешно удалены','Информация',MessageBoxButtons.OK,MessageBoxIcon.information)
end;

procedure Form1.maskedTextBox1_MaskInputRejected(sender: Object; e: MaskInputRejectedEventArgs);
begin
  
end;

procedure Form1.label4_Click(sender: Object; e: EventArgs);
begin
  
end;

end.
