Unit Unit7;

interface

uses System, System.Drawing, System.Windows.Forms;
var
  n:integer;
type
  Form1 = class(Form)
  {$region FormDesigner}
  private
    {$resource Unit7.Form1.resources}
    {$include Unit7.Form1.inc}
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

end.
