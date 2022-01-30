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
      dataGridView1.ColumnCount:=5;
      n:=input();
      for i:=1 to n do begin
        DataGridView1[0,i-1].Value:=inttostr(i);
        DataGridView1[1,i-1].Value:=products[i].Get_name;
        DataGridView1[2,i-1].Value:=products[i].Get_Entry.ToShortDateString;
        DataGridView1[3,i-1].Value:=inttostr(products[i].Get_Price);
        DataGridView1[4,i-1].Value:=inttostr(products[i].Get_Production);
      end;
    end;
  end;

implementation
uses unit1,unit5,unit6,unit8;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
var
  i:integer;
begin
  for i:=1 to n do
    products[i]:=nil;
  form(new unit1.form1).Show;
  self.Close;
end;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
var
  i:integer;
begin
  dataGridView1.Rows.Clear;
  dataGridView1.RowCount:=1000;
  dataGridView1.ColumnCount:=5;
  for i:=1 to n do begin
    DataGridView1[0,i-1].Value:=inttostr(i);
    DataGridView1[1,i-1].Value:=products[i].Get_name;
    DataGridView1[2,i-1].Value:=products[i].Get_Entry.ToShortDateString;
    DataGridView1[3,i-1].Value:=inttostr(products[i].Get_Price);
    DataGridView1[4,i-1].Value:=inttostr(products[i].Get_Production);
  end;
end;

procedure Form1.button3_Click(sender: Object; e: EventArgs); 
begin
  form(new unit5.form1(dataGridView1,n)).Show;
end;

procedure Form1.label4_Click(sender: Object; e: EventArgs);
begin
  
end;

procedure Form1.button4_Click(sender: Object; e: EventArgs);
var
  i:integer;
  maxpr:product;
  res:string;
begin
  maxpr:=products[1];
  for i:=1 to n do begin
    if products[i].Get_Production > maxpr.Get_Production then
      maxpr:=products[i];
  end;
  res:= 'Продукт: ' + maxpr.Get_Name + ', выпущенный ' + maxpr.Get_Entry.ToShortDateString + ' имеет наибольшую стоимость партии: ' + products[i].Get_Production;
  messageBox.Show(res,'Информация',MessageBoxButtons.OK,MessageBoxIcon.Information);
end;

procedure Form1.button5_Click(sender: Object; e: EventArgs);

begin
  form(new unit6.form1(dataGridView1,n)).Show;
end;

procedure Form1.button6_Click(sender: Object; e: EventArgs);
begin
  if n>1 then 
    form(new unit8.form1(n)).Show;
end;

end.
