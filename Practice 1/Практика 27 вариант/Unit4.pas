Unit Unit4;

interface

uses System, System.Drawing, System.Windows.Forms,mine;
var
  n:integer;
type
  Form1 = class(Form)
    procedure button1_Click(sender: Object; e: EventArgs);
    procedure button2_Click(sender: Object; e: EventArgs);
    procedure button3_Click(sender: Object; e: EventArgs);
    procedure label4_Click(sender: Object; e: EventArgs);
    procedure button4_Click(sender: Object; e: EventArgs);
    procedure button5_Click(sender: Object; e: EventArgs);
    procedure button6_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit4.Form1.resources}
    button1: Button;
    button2: Button;
    button3: Button;
    label1: &Label;
    button4: Button;
    button5: Button;
    button6: Button;
    Column1: DataGridViewTextBoxColumn;
    Column2: DataGridViewTextBoxColumn;
    Column3: DataGridViewTextBoxColumn;
    Column4: DataGridViewTextBoxColumn;
    Column5: DataGridViewTextBoxColumn;
    Column6: DataGridViewTextBoxColumn;
    dataGridView1: DataGridView;
    {$include Unit4.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    var
      i:integer;
    begin
      InitializeComponent;
      assign(f,'file.dat');
      reset(f);
      i:=1;
      dataGridView1.RowCount:=1000;
      dataGridView1.ColumnCount:=6;
      n:=input();
      for i:=1 to n do begin
        DataGridView1[0,i-1].Value:=inttostr(i);
        DataGridView1[1,i-1].Value:=inttostr(lines[i].Get_number);
        DataGridView1[2,i-1].Value:=lines[i].Get_name;
        DataGridView1[3,i-1].Value:=inttostr(lines[i].Get_year);
        DataGridView1[4,i-1].Value:=inttostr(lines[i].Get_length);
        DataGridView1[5,i-1].Value:=inttostr(lines[i].Get_count);
      end;
    end;
  end;

implementation
uses unit1,unit5,unit8;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
var
  i:integer;
begin
  for i:=1 to n do
    lines[i]:=nil;
  form(new unit1.form1).Show;
  self.Close;
end;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
var
  i:integer;
begin
  for i:=1 to n do
    lines[i]:=nil;
  n:=input;
  dataGridView1.Rows.Clear;
  dataGridView1.RowCount:=1000;
  dataGridView1.ColumnCount:=6;
  for i:=1 to n do begin
    DataGridView1[0,i-1].Value:=inttostr(i);
    DataGridView1[1,i-1].Value:=inttostr(lines[i].Get_number);
    DataGridView1[2,i-1].Value:=lines[i].Get_name;
    DataGridView1[3,i-1].Value:=inttostr(lines[i].Get_year);
    DataGridView1[4,i-1].Value:=inttostr(lines[i].Get_length);
    DataGridView1[5,i-1].Value:=inttostr(lines[i].Get_count);
  end;
end;

procedure Form1.button3_Click(sender: Object; e: EventArgs);
var i,j:integer; 
begin
  for i:=1 to n do begin
    for j:=i+1 to n do begin
      if lines[j].Get_length > lines[i].Get_length then begin
        (lines[i],lines[j]):=(lines[j],lines[i]);
      end;
    end;
  end;
  
  dataGridView1.Rows.Clear;
  dataGridView1.RowCount:=1000;
  dataGridView1.ColumnCount:=6;
  for i:=1 to n do begin
    DataGridView1[0,i-1].Value:=inttostr(i);
    DataGridView1[1,i-1].Value:=inttostr(lines[i].Get_number);
    DataGridView1[2,i-1].Value:=lines[i].Get_name;
    DataGridView1[3,i-1].Value:=inttostr(lines[i].Get_year);
    DataGridView1[4,i-1].Value:=inttostr(lines[i].Get_length);
    DataGridView1[5,i-1].Value:=inttostr(lines[i].Get_count);
  end;
  
end;

procedure Form1.label4_Click(sender: Object; e: EventArgs);
begin
  
end;

procedure Form1.button4_Click(sender: Object; e: EventArgs);
begin
  form(new unit5.form1(dataGridView1,n)).Show;
end;

procedure Form1.button5_Click(sender: Object; e: EventArgs);
var 
  i:integer;
  average:real:=0;
  text:string;
begin
  for i:=1 to n do begin
    average+=lines[i].Get_average_length
  end;
  average/=n;
  text:='Средняя длина перегона между станциями равна '+floattostr(average)+' км';
  messageBox.Show(text,'Информация',MessageBoxButtons.OK,MessageBoxIcon.information)
end;

procedure Form1.button6_Click(sender: Object; e: EventArgs);
begin
  if n>1 then 
    form(new unit8.form1(n)).Show;
end;

end.
