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
    label5: &Label;
    maskedTextBox5: MaskedTextBox;
    maskedTextBox4: MaskedTextBox;
    label4: &Label;
    maskedTextBox3: MaskedTextBox;
    label3: &Label;
    maskedTextBox2: MaskedTextBox;
    label2: &Label;
    maskedTextBox1: MaskedTextBox;
    label1: &Label;
    button3: Button;
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
  name1:string;
  year1,number1,length1,count1:integer;
  l_file:line_File;
  i,n,j:integer;
  key:boolean:=false;
begin
  if (maskedtextbox1.Text='') or (maskedtextbox2.Text='') or (maskedtextbox3.Text='') or (maskedtextbox4.Text='')  or (maskedtextbox5.Text='') then exit;
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
  n:=input();
  for i:=1 to n do begin
    if lines[i].Is_equally(l_file) then begin
      key:=true;
      for j:=i to n-1 do
        lines[j]:=lines[j+1];
      lines[n]:=nil;
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
    with l_file do begin
      name:=lines[i].Get_name;
      year:=lines[i].Get_year;
      number:=lines[i].Get_number;
      length:=lines[i].Get_length;
      count:=lines[i].Get_count;
    end;
    write(f,l_file);
    lines[i]:=nil;
  end;
  closefile(f);
  maskedtextbox1.Text:='';
  maskedtextbox2.Text:='';
  maskedtextbox3.Text:='';
  maskedtextbox4.Text:='';
  maskedtextbox5.Text:='';
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
