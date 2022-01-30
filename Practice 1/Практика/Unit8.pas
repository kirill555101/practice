Unit Unit8;

interface

uses System, System.Drawing, System.Windows.Forms;
var
  n:integer;
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
    constructor(num:integer);
    begin
      InitializeComponent;
      n:=num;
      make_function();
    end;
    procedure make_function();
  end;
  
function count(y:integer):integer;

implementation
uses mine;

var
  graph:graphics;
  bmp:bitmap;
  myFont:font := new Font('Times New Roman', 11);
  brush1:solidbrush:=new SolidBrush(color.black);
  p:point;
  pen1:pen;
  
procedure form1.make_function();
var
  i,min,max,move:integer;
begin
  pen1:=new Pen(color.black);
  p:=new Point(0,picturebox1.height-20);
  bmp:=new Bitmap(picturebox1.Width,picturebox1.height);
  graph := Graphics.fromimage(bmp);
  pictureBox1.Image := bmp;
  i:=0;
  pen1.DashStyle:=system.Drawing.drawing2d.DashStyle.dash;
  while i<=20 do begin
    graph.DrawString(inttostr(i),myfont,brush1,p.X,p.y-7);
    i+=1;
    p.Y-=24;
    graph.DrawLine(pen1,20,p.y,picturebox1.width,p.y);
  end;
  pen1.DashStyle:=system.Drawing.drawing2d.DashStyle.solid;
  graph.DrawLine(pen1,20,picturebox1.height-20,20,0);
  graph.DrawLine(pen1,20,picturebox1.height-20,picturebox1.width,picturebox1.height-20);
  min:=products[1].Get_release_date.year;
  max:=products[1].Get_release_date.year;
  for i:=1 to n do begin
    if products[i].Get_release_date.year<min then
      min:=products[i].Get_release_date.year;
    if products[i].Get_release_date.year>max then
      max:=products[i].Get_release_date.year;
  end;
  if max=min then begin
    messageBox.Show('Одинаковые данные!','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.Error);
    exit;
  end;
  move:=round(picturebox1.width/(max-min))-15;
  p:=new Point(45,picturebox1.height-15);
  pen1.Color:=color.Blue;
  for i:=min to max do begin
    brush1.Color:=color.blue;
    graph.DrawRectangle(pen1,p.x,p.Y-5-24*count(i),30,24*count(i));
    graph.FillRectangle(brush1,p.x,p.Y-5-24*count(i),30,24*count(i));
    brush1.Color:=color.Black;
    graph.DrawString(inttostr(i),myfont,brush1,p);
    p.x+=move;
  end;
end;

function count(y:integer):integer;
var
  i:integer;
begin
  result:=0;
  for i:=1 to n do 
    if products[i].Get_release_date.year=y then result+=1;
end;

procedure Form1.label1_Click(sender: Object; e: EventArgs);
begin
  
end;

procedure Form1.label2_Click(sender: Object; e: EventArgs);
begin
  
end;

end.
