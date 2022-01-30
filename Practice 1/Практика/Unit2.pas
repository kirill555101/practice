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
  name1:string;
  dstr:string;
  d:date;
  company1:string;
  mem:string;
  memory1:integer;
  pr_file:Product_File;
  i:integer;
begin
  if (maskedtextbox1.Text='') or (maskedtextbox2.Text='') or (maskedtextbox3.Text='') or (maskedtextbox4.Text='') then exit;
  name1:=maskedtextbox1.Text;
  dstr:=maskedtextbox2.Text;
  if (length(dstr)<10) then begin
    messageBox.Show('Неверная форма времени. Укажите полную дату!','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.Error);
    exit;
  end;
  d.day:=strtoint(dstr[1]+dstr[2]);
  d.month:=strtoint(dstr[4]+dstr[5]);
  d.year:=strtoint(dstr[7]+dstr[8]+dstr[9]+dstr[10]);
  company1:=maskedtextbox3.Text;
  mem:=maskedtextbox4.Text;
  for i:=1 to length(mem) do
    if (mem[i] in ['a'..'z']) or (mem[i] in ['A'..'Z']) or (mem[i] in ['а'..'я']) or (mem[i] in ['А'..'Я']) then begin
      messageBox.Show('Неверная форма записи ОЗУ. Она должна включать только цифры!','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.Error);
      exit;
    end;
  memory1 := strtoint(maskedtextbox4.Text);
  with pr_file do begin
    name:=name1;
    release:=d;
    company:=company1;
    memory:=memory1;
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
