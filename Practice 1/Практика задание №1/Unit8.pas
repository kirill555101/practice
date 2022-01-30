unit Unit8;

interface

uses System, System.Drawing, System.Windows.Forms;

var
  n: integer;

type
  Form1 = class(Form)
    procedure label1_Click(sender: Object; e: EventArgs);
    procedure label2_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit8.Form1.resources}
    label1: &Label;
    label2: &Label;
    pictureBox1: PictureBox;
    {$include Unit8.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor(num: integer);
    begin
      InitializeComponent;
      n := num;
      make_function();
    end;
    
    procedure make_function();
  end;

function count(d: integer): integer;

implementation

uses mine;

var
  graph: graphics;
  bmp: bitmap;
  myFont: font := new Font('Times New Roman', 11);
  brush1: solidbrush := new SolidBrush(color.black);
  p: point;
  pen1: pen;

procedure form1.make_function();
var
  i, min, max, move: integer;
begin
  pen1 := new Pen(color.black);
  p := new Point(0, picturebox1.height - 20);
  bmp := new Bitmap(picturebox1.Width, picturebox1.height);
  graph := Graphics.fromimage(bmp);
  pictureBox1.Image := bmp;
  i := 0;
  pen1.DashStyle := system.Drawing.drawing2d.DashStyle.dash;
  while i <= 2000 do
  begin
    graph.DrawString(inttostr(i), myfont, brush1, p.X, p.y - 7);
    i += 100;
    p.Y -= 24;
    graph.DrawLine(pen1, 37, p.y, picturebox1.width, p.y);
  end;
  pen1.DashStyle := system.Drawing.drawing2d.DashStyle.solid;
  graph.DrawLine(pen1, 37, picturebox1.height - 20, 37, 0);
  graph.DrawLine(pen1, 37, picturebox1.height - 20, picturebox1.width, picturebox1.height - 20);
  min := lists[1].Get_Days;
  max := lists[1].Get_Days;
  for i := 1 to n do
  begin
    if lists[i].Get_Days < min then
      min := lists[i].Get_Days;
    if lists[i].Get_Days > max then
      max := lists[i].Get_Days;
  end;
  if max = min then begin
    messageBox.Show('Одинаковые данные!', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.Error);
    exit;
  end;
  move := round(picturebox1.width / (max - min)) - 30;
  p := new Point(57, picturebox1.height - 15);
  pen1.Color := color.Blue;
  for i := min to max do
  begin
    brush1.Color := color.blue;
    graph.DrawRectangle(pen1, p.x, p.Y - 5 - 24 * (count(i) div 100), 30, 24 * (count(i) div 100));
    graph.FillRectangle(brush1, p.x, p.Y - 5 - 24 * (count(i) div 100), 30, 24 * (count(i) div 100));
    brush1.Color := color.Black;
    graph.DrawString(inttostr(i), myfont, brush1, p.X + 7, p.y);
    p.x += move;
  end;
end;

function count(d: integer): integer;
var
  i, k: integer;
  res: real;
  key : boolean:=false;
begin
  res := 0;
  k := 0;
  for i := 1 to n do 
    if lists[i].Get_Days = d then 
    begin
      res += lists[i].Get_Price;
      k += 1;
      key := true;
    end;
  if key then
    result := round(res / k)
  else
    result := 0;
end;

procedure Form1.label1_Click(sender: Object; e: EventArgs);
begin
  
end;

procedure Form1.label2_Click(sender: Object; e: EventArgs);
begin
  
end;

end.
