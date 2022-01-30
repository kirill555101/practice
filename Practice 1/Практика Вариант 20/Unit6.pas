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
    maskedTextBox3: MaskedTextBox;
    maskedTextBox2: MaskedTextBox;
    label5: &Label;
    label4: &Label;
    label3: &Label;
    maskedTextBox1: MaskedTextBox;
    button1: Button;
    label1: &Label;
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
  s:string;
  i,k:integer;
  company:string;
  first,last:integer;
  key:boolean:=false;
  release:date;
begin
  if (maskedtextbox1.text='') or (maskedtextbox2.text='') or (maskedtextbox3.text='') then exit;
  s:=maskedtextbox2.text;
  for i:=1 to length(s) do
    if (s[i] in ['a'..'z']) or (s[i] in ['A'..'Z']) or (s[i] in ['а'..'я']) or (s[i] in ['А'..'Я']) then begin
      messageBox.Show('Неверная форма записи года. Она должна включать только цифры!','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.Error);
      exit;
    end;
  s:=maskedtextbox3.text;
  for i:=1 to length(s) do
    if (s[i] in ['a'..'z']) or (s[i] in ['A'..'Z']) or (s[i] in ['а'..'я']) or (s[i] in ['А'..'Я']) then begin
      messageBox.Show('Неверная форма записи года. Она должна включать только цифры!','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.Error);
      exit;
    end;
  company:=maskedtextbox1.Text;
  first:=strtoint(maskedtextbox2.Text);
  last:=strtoint(maskedtextbox3.Text);
  for i:=1 to n do
    if products[i].Is_released_in_period(company,first,last) then begin
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
   if products[i].Is_released_in_period(company,first,last) then begin
     release:=products[i].Get_release_date;
     DataGridView1[0,k-1].Value:=inttostr(k);
     DataGridView1[1,k-1].Value:=products[i].Get_name;
     DataGridView1[2,k-1].Value:=release.day+'/'+release.month+'/'+release.year;
     DataGridView1[3,k-1].Value:=products[i].Get_company_name;
     DataGridView1[4,k-1].Value:=inttostr(products[i].Get_memory);
     k+=1;
  end;
  maskedtextbox1.Text:='';
  maskedtextbox2.Text:='';
  maskedtextbox3.Text:='';
end;

end.
