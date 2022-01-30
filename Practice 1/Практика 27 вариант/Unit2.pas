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
    maskedTextBox5: MaskedTextBox;
    label5: &Label;
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
  name1:string;
  year1,number1,length1,count1:integer;
  l_file:line_File;
  i:integer;
begin
  if (maskedtextbox1.Text='') or (maskedtextbox2.Text='') or (maskedtextbox3.Text='') or (maskedtextbox4.Text='') or (maskedtextbox5.Text='') then exit;
  number1:=strtoint(maskedtextbox5.Text);
  name1:=maskedtextbox1.Text;
  year1:=strtoint(maskedtextbox2.Text);
  length1:=strtoint(maskedtextbox3.Text);
  count1:=strtoint(maskedtextbox4.Text);
  for i:=1 to length(name1) do
    if (name1[i] in ['0'..'9']) then begin
      messageBox.Show('Неверная форма записи названия. Оно должна включать только буквы!','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.Error);
      exit;
    end;
  with l_file do begin
    name:=name1;
    year:=year1;
    number:=number1;
    length:=length1;
    count:=count1;
  end;
  assign(f,'file.dat');
  reset(f);
  Seek(f, FileSize(f));
  write(f,l_file);
  closefile(f);
  maskedtextbox1.Text:='';
  maskedtextbox2.Text:='';
  maskedtextbox3.Text:='';
  maskedtextbox4.Text:='';
  maskedtextbox5.Text:='';
end;

procedure Form1.maskedTextBox1_MaskInputRejected(sender: Object; e: MaskInputRejectedEventArgs);
begin
  
end;

procedure Form1.label4_Click(sender: Object; e: EventArgs);
begin
  
end;

end.
