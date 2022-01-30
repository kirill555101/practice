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
        DataGridView1[1,i-1].Value:=lists[i].Get_Service;
        DataGridView1[2,i-1].Value:=lists[i].Get_Surname;
        DataGridView1[3,i-1].Value:=inttostr(lists[i].Get_Days);
        DataGridView1[4,i-1].Value:=inttostr(lists[i].Get_Price);
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
    lists[i]:=nil;
  form(new unit1.form1).Show;
  self.Close;
end;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
var
  i:integer;
begin
  DataGridView1.Columns[2].HeaderText := 'Фамилия мастера';
  DataGridView1.Columns[3].HeaderText := 'Срок выполнения заказа в днях';
  DataGridView1.Columns[4].HeaderText := 'Стоимость услуги';
  dataGridView1.Rows.Clear;
  dataGridView1.RowCount:=1000;
  dataGridView1.ColumnCount:=5;
  for i:=1 to n do begin
    DataGridView1[0,i-1].Value:=inttostr(i);
    DataGridView1[1,i-1].Value:=lists[i].Get_Service;
    DataGridView1[2,i-1].Value:=lists[i].Get_Surname;
    DataGridView1[3,i-1].Value:=inttostr(lists[i].Get_Days);
    DataGridView1[4,i-1].Value:=inttostr(lists[i].Get_Price);
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
  service:string;
  i,j,k,count:integer;
begin
  dataGridView1.Rows.Clear;
  dataGridView1.RowCount:=1000;
  dataGridView1.ColumnCount:=5;
  DataGridView1.Columns[2].HeaderText := 'Количество';
  DataGridView1.Columns[3].HeaderText := '';
  DataGridView1.Columns[4].HeaderText := '';
  k:=1;
  while n>1 do begin
    count:=0;
    service:=lists[1].Get_Service;
    for i:=1 to n do
      if (service = lists[i].Get_Service) then
        count += 1;
    DataGridView1[0,k-1].Value:=inttostr(k);
    DataGridView1[1,k-1].Value:=service;
    DataGridView1[2,k-1].Value:=inttostr(count);
    k+=1;
    i:=1;
    while i<=n do begin
      if service = lists[1].Get_Service then begin
          for j:=i to n-1 do
            lists[j]:=lists[j+1];
        lists[n]:=nil;
        n-=1;
      end
      else
        i+=1;
    end;
  end;
  n:=input();
end;

procedure Form1.button5_Click(sender: Object; e: EventArgs);
begin
  form(new unit6.form1(n)).Show;
end;

procedure Form1.button6_Click(sender: Object; e: EventArgs);
begin
  if n>1 then 
    form(new unit8.form1(n)).Show;
end;

end.
