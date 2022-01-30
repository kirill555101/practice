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
    Column1: DataGridViewTextBoxColumn;
    Column2: DataGridViewTextBoxColumn;
    Column3: DataGridViewTextBoxColumn;
    Column4: DataGridViewTextBoxColumn;
    Column5: DataGridViewTextBoxColumn;
    button6: Button;
    dataGridView1: DataGridView;
    {$include Unit4.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    var
      i:integer;
      release:date;
    begin
      InitializeComponent;
      assign(f,'file.dat');
      reset(f);
      i:=1;
      dataGridView1.RowCount:=1000;
      dataGridView1.ColumnCount:=5;
      n:=input();
      for i:=1 to n do begin
        release:=products[i].Get_release_date;
        DataGridView1[0,i-1].Value:=inttostr(i);
        DataGridView1[1,i-1].Value:=products[i].Get_name;
        DataGridView1[2,i-1].Value:=release.day+'/'+release.month+'/'+release.year;
        DataGridView1[3,i-1].Value:=products[i].Get_company_name;
        DataGridView1[4,i-1].Value:=inttostr(products[i].Get_memory);
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
  release:date;
begin
  dataGridView1.Rows.Clear;
  dataGridView1.RowCount:=1000;
  dataGridView1.ColumnCount:=5;
  for i:=1 to n do begin
    release:=products[i].Get_release_date;
    DataGridView1[0,i-1].Value:=inttostr(i);
    DataGridView1[1,i-1].Value:=products[i].Get_name;
    DataGridView1[2,i-1].Value:=release.day+'/'+release.month+'/'+release.year;
    DataGridView1[3,i-1].Value:=products[i].Get_company_name;
    DataGridView1[4,i-1].Value:=inttostr(products[i].Get_memory);
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
begin
  form(new unit6.form1(dataGridView1,n)).Show;
end;

procedure Form1.button5_Click(sender: Object; e: EventArgs);
var
  company:string;
  i,j,k:integer;
  mem:integer;
  pr:product;
  release:date;
begin
  dataGridView1.Rows.Clear;
  dataGridView1.RowCount:=1000;
  dataGridView1.ColumnCount:=5;
  k:=1;
  while n>0 do begin
    company:=products[1].Get_company_name;
    mem:=products[1].Get_memory;
    pr:=products[1];
    for i:=1 to n do
      if (mem<products[i].Get_memory) and (company=products[i].Get_company_name) then begin
        pr:=products[i];
        mem:=products[i].Get_memory;
      end;
    release:=pr.Get_release_date;
    DataGridView1[0,k-1].Value:=inttostr(k);
    DataGridView1[1,k-1].Value:=pr.Get_name;
    DataGridView1[2,k-1].Value:=release.day+'/'+release.month+'/'+release.year;
    DataGridView1[3,k-1].Value:=pr.Get_company_name;
    DataGridView1[4,k-1].Value:=inttostr(pr.Get_memory);
    k+=1;
    i:=1;
    while i<=n do begin
      if company=products[i].Get_company_name then begin
          for j:=i to n-1 do
            products[j]:=products[j+1];
        products[n]:=nil;
        n-=1;
      end
      else
        i+=1;
    end;
  end;
  n:=input();
end;

procedure Form1.button6_Click(sender: Object; e: EventArgs);
begin
  if n>1 then 
    form(new unit8.form1(n)).Show;
end;

end.
