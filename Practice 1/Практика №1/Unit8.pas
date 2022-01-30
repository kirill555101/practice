Unit Unit8;

interface

uses System, System.Drawing, System.Windows.Forms;
var
  n:integer;
type
  Form1 = class(Form)
    procedure label1_Click(sender: Object; e: EventArgs);
    procedure label2_Click(sender: Object; e: EventArgs);
    procedure button1_Click(sender: Object; e: EventArgs);
    procedure button2_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit8.Form1.resources}
    label1: &Label;
    label2: &Label;
    button1: Button;
    maskedTextBox1: MaskedTextBox;
    label3: &Label;
    button2: Button;
    pictureBox1: PictureBox;
    {$include Unit8.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor(num:integer);
    begin
      InitializeComponent;
      n:=num;
      make_base()
    end;
    procedure make_function();
    procedure make_base();
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
  name1:string;

procedure form1.make_base();
var
  i: integer;
begin
  pen1 := new Pen(color.black);
  p := new Point(0, picturebox1.height - 20);
  bmp := new Bitmap(picturebox1.Width, picturebox1.height);
  graph := Graphics.fromimage(bmp);
  pictureBox1.Image := bmp;
  i := 0;
  pen1.DashStyle := system.Drawing.drawing2d.DashStyle.dash;
  while i <= 200 do
  begin
    graph.DrawString(inttostr(i), myfont, brush1, p.X, p.y - 7);
    i += 10;
    p.Y -= 24;
    graph.DrawLine(pen1, 37, p.y, picturebox1.width, p.y);
  end;
  pen1.DashStyle := system.Drawing.drawing2d.DashStyle.solid;
  graph.DrawLine(pen1, 37, picturebox1.height - 20, 37, 0);
  graph.DrawLine(pen1, 37, picturebox1.height - 20, picturebox1.width, picturebox1.height - 20);
end;
 
procedure form1.make_function();
var
  i,min,max,move:integer;
begin
  pen1 := new Pen(color.black);
  p := new Point(0, picturebox1.height - 20);
  bmp := new Bitmap(picturebox1.Width, picturebox1.height);
  graph := Graphics.fromimage(bmp);
  pictureBox1.Image := bmp;
  i := 0;
  pen1.DashStyle := system.Drawing.drawing2d.DashStyle.dash;
  while i <= 200 do
  begin
    graph.DrawString(inttostr(i), myfont, brush1, p.X, p.y - 7);
    i += 10;
    p.Y -= 24;
    graph.DrawLine(pen1, 37, p.y, picturebox1.width, p.y);
  end;
  pen1.DashStyle := system.Drawing.drawing2d.DashStyle.solid;
  graph.DrawLine(pen1, 37, picturebox1.height - 20, 37, 0);
  graph.DrawLine(pen1, 37, picturebox1.height - 20, picturebox1.width, picturebox1.height - 20);
  min:=products[1].Get_Entry.year;
  max:=products[1].Get_Entry.year;
  for i:=1 to n do begin
    if (products[i].Get_Entry.year<min) and (products[i].Get_Name = name1) then
      min:=products[i].Get_Entry.year;
    if (products[i].Get_Entry.year>max) and (products[i].Get_Name = name1) then
      max:=products[i].Get_Entry.year;
  end;
  if max=min then begin
    messageBox.Show('Одинаковые данные!','Ошибка',MessageBoxButtons.OK,MessageBoxIcon.Error);
    exit;
  end;
  move:=round(picturebox1.width/(max-min))-40;
  p:=new Point(57,picturebox1.height-15);
  pen1.Color:=color.Blue;
  for i:=min to max do begin
    brush1.Color:=color.blue;
    graph.DrawRectangle(pen1,p.x,p.Y-5-24*(count(i) div 10000),30,24*(count(i) div 10000));
    graph.FillRectangle(brush1,p.x,p.Y-5-24*(count(i) div 10000),30,24*(count(i) div 10000));
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
    if (products[i].Get_Name = name1) and (products[i].Get_Entry.year = y) then
    begin
      result := products[i].Get_Production;
      break;
    end;
end;

procedure Form1.label1_Click(sender: Object; e: EventArgs);
begin
  
end;

procedure Form1.label2_Click(sender: Object; e: EventArgs);
begin
  
end;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
var
  i:integer;
  key:boolean;
  s:string;
begin
  if (maskedtextbox1.Text = '') then exit;
  key:=false;
  s := maskedtextbox1.Text;
  for i:=1 to n do
    if products[i].Get_name=s then begin
      key:=true;
      break;
    end;
  if not key then begin
    messageBox.Show('Данные не найдены', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.Error);
    exit;
  end;
  name1 := maskedtextbox1.Text;
  make_function();
  maskedtextbox1.Enabled := false;
end;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
begin
  pictureBox1.Image := nil;
  make_base();
  maskedtextbox1.Text := '';
  maskedtextbox1.Enabled := true;
end;

end.
