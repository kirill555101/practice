Unit Unit6;

interface

uses System, System.Drawing, System.Windows.Forms;
var
  n:integer;
type
  Form1 = class(Form)
    procedure button3_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit6.Form1.resources}
    maskedTextBox1: MaskedTextBox;
    button1: Button;
    label2: &Label;
    {$include Unit6.Form1.inc}
  {$endregion FormDesigner}
  public
    dataGridView1:dataGridView;
    constructor(var data: DataGridView;num:integer);
    begin
      InitializeComponent;
      DataGridView1:=data;
      n:=num;
    end;
  end;

implementation
uses mine;

procedure Form1.button3_Click(sender: Object; e: EventArgs);
var
  i,production,k,sum:integer;
  s,res:string;
  key:boolean:=false;
begin
  if (maskedtextbox1.text='') then exit;
  s:=maskedtextbox1.text;
  for i:=1 to length(s) do
    if (s[i] in ['a'..'z']) or (s[i] in ['A'..'Z']) or (s[i] in ['а'..'я']) or (s[i] in ['А'..'Я']) then begin
      messageBox.Show('Неверная форма записи года. Она должна включать только цифры!','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.Error);
      exit;
    end;
  production:=strtoint(maskedtextbox1.text);
  for i:=1 to n do
    if products[i].Get_Production >= production then begin
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
  sum:=0;
  for i:=1 to n do
   if products[i].Get_Production >= production then begin
     DataGridView1[0,k-1].Value:=inttostr(i);
     DataGridView1[1,k-1].Value:=products[i].Get_name;
     DataGridView1[2,k-1].Value:=products[i].Get_Entry.ToShortDateString;
     DataGridView1[3,k-1].Value:=inttostr(products[i].Get_Price);
     DataGridView1[4,k-1].Value:=inttostr(products[i].Get_Production);
     k+=1;
     sum += products[i].Get_Production;
  end;
  res:= 'Общая стоимость партий равна ' + inttostr(sum);
  messageBox.Show(res,'Инормация',MessageBoxButtons.OK,MessageBoxIcon.Information);
  maskedtextbox1.Text:='';
end;

end.
