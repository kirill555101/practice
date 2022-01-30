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
    constructor(num:integer);
    begin
      InitializeComponent;
      n:=num;
    end;
  end;

implementation
uses mine;

procedure Form1.button3_Click(sender: Object; e: EventArgs);
var
  service,res:string;
  i:integer;
  pr:pricelist;
  key:boolean:=false;
begin
  if (maskedtextbox1.text='') then exit;
  service:=maskedtextbox1.text;
  pr:=lists[1];
  for i:=1 to n do
    if (lists[i].Get_Service = service) and (lists[i].Get_Price < pr.Get_Price) then begin
      key:=true;
      pr:=lists[i];
      break;
    end;
  if not key then begin
    messageBox.Show('Услуга не найдена','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.error);
    exit;
  end;
  res:='Услуга ' + pr.Get_Service + ' дешевле всего обойдется у мастера с фамилией ' + pr.Get_Surname;
  messageBox.Show(res,'Информация',MessageBoxButtons.OK,MessageBoxIcon.information);
  maskedtextbox1.Text:='';
end;

end.
