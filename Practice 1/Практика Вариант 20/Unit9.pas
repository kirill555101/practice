unit Unit9;

interface

uses System, System.Drawing, System.Windows.Forms;

var
  n: integer;

type
  Form1 = class(Form)
    procedure button1_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit9.Form1.resources}
    button1: Button;
    maskedTextBox1: MaskedTextBox;
    label1: &Label;
    {$include Unit9.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor(num: integer);
    begin
      n := num;
      InitializeComponent;
    end;
  end;

implementation

uses mine;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
var
  name: string;
  count: integer := 0;
  i: integer;
  key: boolean := false;
  res: string := '';
begin
  if (maskedtextbox1.Text = '') then exit;
  name := maskedtextbox1.Text;
  for i := 1 to n do
    if name = cities[i].Get_name then begin
      key := true;
      break;
    end;
  if not key then begin
    messageBox.Show('Данные не найдены', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.error);
    exit;
  end;
  for i := 1 to n do
    if name = cities[i].Get_name then count += 1;
  
  res := 'Количество проведенных переписей населения в городе ' + name + ' равно: ' + inttostr(count);
  messageBox.Show(res, 'Информация', MessageBoxButtons.OK, MessageBoxIcon.information)
end;

end.
