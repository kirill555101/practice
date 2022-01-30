﻿Unit Unit5;

interface

uses System, System.Drawing, System.Windows.Forms;
var
  n:integer;
type
  Form1 = class(Form)
    procedure button3_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit5.Form1.resources}
    button1: Button;
    maskedTextBox1: MaskedTextBox;
    label1: &Label;
    {$include Unit5.Form1.inc}
  {$endregion FormDesigner}
  public
    dataGridView1:dataGridView;
    constructor(var data: DataGridView;num:integer);
    begin
      InitializeComponent;
      dataGridView1:=data;
      n:=num;
    end;
  end;

implementation
uses mine;

procedure Form1.button3_Click(sender: Object; e: EventArgs);
var
  mem:integer;
  i:integer;
  release:date;
  key:boolean:=false;
  k:integer;
begin
  if maskedtextbox1.text='' then exit;
  mem:=strtoint(maskedtextbox1.text);
  for i:=1 to n do
    if products[i].Is_enough_memory(mem) then begin
      key:=true;
      break;
    end;
  if not key then begin
    messageBox.Show('Данные не найдены','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.error);
    exit;
  end;
  dataGridView1.Rows.Clear;
  dataGridView1.RowCount:=1000;
  dataGridView1.ColumnCount:=5;
  k:=1;
  for i:=1 to n do
    if products[i].Is_enough_memory(mem) then begin
      release:=products[i].Get_release_date;
      DataGridView1[0,k-1].Value:=inttostr(k);
      DataGridView1[1,k-1].Value:=products[i].Get_name;
      DataGridView1[2,k-1].Value:=release.day+'/'+release.month+'/'+release.year;
      DataGridView1[3,k-1].Value:=products[i].Get_company_name;
      DataGridView1[4,k-1].Value:=inttostr(products[i].Get_memory);
      k+=1;
    end;
  maskedtextbox1.text:='';
  
end;

end.
