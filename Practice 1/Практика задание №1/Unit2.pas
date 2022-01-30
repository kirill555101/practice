Unit Unit2;

interface

uses System, System.Drawing, System.Windows.Forms,mine;

type
  Form1 = class(Form)
    procedure button2_Click(sender: Object; e: EventArgs);
    procedure button1_Click(sender: Object; e: EventArgs);
    procedure maskedTextBox1_MaskInputRejected(sender: Object; e: MaskInputRejectedEventArgs);
    procedure label4_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit2.Form1.resources}
    label1: &Label;
    label2: &Label;
    maskedTextBox2: MaskedTextBox;
    label3: &Label;
    maskedTextBox3: MaskedTextBox;
    label4: &Label;
    maskedTextBox4: MaskedTextBox;
    button1: Button;
    button2: Button;
    maskedTextBox1: MaskedTextBox;
    {$include Unit2.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
    end;
  end;

implementation
uses unit1;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
begin
  form(new unit1.form1).Show;
  self.Close;
end;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
var
  service1:string;
  days1:integer;
  surname1:string;
  price1:integer;
  s:string;
  pr_file:Pricelist_File;
  i:integer;
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
  Seek(f, FileSize(f));
  write(f,pr_file);
  closefile(f);
  maskedtextbox1.Text:='';
  maskedtextbox2.Text:='';
  maskedtextbox3.Text:='';
  maskedtextbox4.Text:='';
end;

procedure Form1.maskedTextBox1_MaskInputRejected(sender: Object; e: MaskInputRejectedEventArgs);
begin
  
end;

procedure Form1.label4_Click(sender: Object; e: EventArgs);
begin
  
end;

end.
