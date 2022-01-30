unit Unit1;

interface

uses System, System.Drawing, System.Windows.Forms;

type
  Form1 = class(Form)
    procedure button1_Click(sender: Object; e: EventArgs);
    procedure button4_Click(sender: Object; e: EventArgs);
    procedure button2_Click(sender: Object; e: EventArgs);
    procedure button3_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit1.Form1.resources}
    button2: Button;
    button3: Button;
    button4: Button;
    button1: Button;
    {$include Unit1.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
    end;
  end;

implementation

uses unit2, unit3, unit4;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
begin
  form(new unit2.form1).show;
  self.Hide;
end;

procedure Form1.button4_Click(sender: Object; e: EventArgs);
begin
  self.Close;
end;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
begin
  form(new unit3.form1).show;
  self.Hide;
end;

procedure Form1.button3_Click(sender: Object; e: EventArgs);
begin
  form(new unit4.form1).show;
  self.Hide;
end;

end.
