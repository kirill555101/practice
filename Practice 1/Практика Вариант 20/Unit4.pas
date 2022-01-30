unit Unit4;

interface

uses System, System.Drawing, System.Windows.Forms, mine;

var
  n: integer;

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
    dataGridView1: DataGridView;
    {$include Unit4.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    var
      i: integer;
    begin
      InitializeComponent;
      assign(f, 'file.dat');
      reset(f);
      i := 1;
      dataGridView1.RowCount := 1000;
      dataGridView1.ColumnCount := 4;
      n := input();
      for i := 1 to n do
      begin
        DataGridView1[0, i - 1].Value := inttostr(i);
        DataGridView1[1, i - 1].Value := cities[i].Get_name;
        DataGridView1[2, i - 1].Value := cities[i].Get_population;
        DataGridView1[3, i - 1].Value := cities[i].Get_year;
      end;
    end;
  end;

implementation

uses unit1, unit5, unit8, unit9;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
var
  i: integer;
begin
  for i := 1 to n do
    cities[i] := nil;
  form(new unit1.form1).Show;
  self.Close;
end;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
var
  i: integer;
begin
  dataGridView1.Rows.Clear;
  dataGridView1.RowCount := 1000;
  dataGridView1.ColumnCount := 4;
  for i := 1 to n do
  begin
    DataGridView1[0, i - 1].Value := inttostr(i);
    DataGridView1[1, i - 1].Value := cities[i].Get_name;
    DataGridView1[2, i - 1].Value := cities[i].Get_population;
    DataGridView1[3, i - 1].Value := cities[i].Get_year;
  end;
end;

procedure Form1.button3_Click(sender: Object; e: EventArgs);
begin
  form(new unit5.form1(dataGridView1, n)).Show;
end;

procedure Form1.label4_Click(sender: Object; e: EventArgs);
begin
  
end;

procedure Form1.button4_Click(sender: Object; e: EventArgs);
var
  name: string;
  year: int64;
  c: city;
  i, j, k: integer;
  key: boolean := false;
begin
  for i:=1 to n do
    if cities[i].Is_millionaire then begin
      key:=true;
      break;
    end;
  if not key then begin
    messageBox.Show('Города-миллионеры не найдены', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.error);
    exit;
  end;
  dataGridView1.Rows.Clear;
  dataGridView1.RowCount := 1000;
  dataGridView1.ColumnCount := 4;
  k := 1;
  while n > 0 do
  begin
    name := cities[1].Get_name;
    year := cities[1].Get_year;
    c := cities[1];
    for i := 1 to n do
      if (year < cities[i].Get_year) and (name = cities[i].Get_name) and (cities[i].Is_millionaire()) then begin
        c := cities[i];
        year := cities[i].Get_year;
      end;
    if not cities[i].Is_millionaire() then break;
    DataGridView1[0, k - 1].Value := inttostr(i);
    DataGridView1[1, k - 1].Value := cities[i].Get_name;
    DataGridView1[2, k - 1].Value := cities[i].Get_population;
    DataGridView1[3, k - 1].Value := cities[i].Get_year;
    k += 1;
    i := 1;
    while i <= n do
    begin
      if name = cities[i].Get_name then begin
        for j := i to n - 1 do
          cities[j] := cities[j + 1];
        cities[n] := nil;
        n -= 1;
      end
      else
        i += 1;
    end;
  end;
  n := input();
end;

procedure Form1.button5_Click(sender: Object; e: EventArgs);
begin
  form(new unit9.form1(n)).Show;
end;

procedure Form1.button6_Click(sender: Object; e: EventArgs);
begin
  if n > 1 then 
    form(new unit8.form1(n)).Show;
end;

end.
