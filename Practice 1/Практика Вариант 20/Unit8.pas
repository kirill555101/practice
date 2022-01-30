unit Unit8;

interface

uses System, System.Drawing, System.Windows.Forms;

var
  n: integer;

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
    label3: &Label;
    maskedTextBox1: MaskedTextBox;
    button1: Button;
    button2: Button;
    pictureBox1: PictureBox;
    {$include Unit8.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor(num: integer);
    begin
      InitializeComponent;
      n := num;
      make_base();
    end;
    
    procedure make_function();
    procedure make_base();
  end;

function Is_found(y:int64):boolean;
function count(y: int64): int64;

implementation

uses mine;

var
  graph: graphics;
  bmp: bitmap;
  myFont: font := new Font('Times New Roman', 11);
  brush1: solidbrush := new SolidBrush(color.black);
  p: point;
  pen1: pen;
  name1: string;
  j: integer := 1;

procedure form1.make_function();
var
  i: integer;
  min, max, move: int64;
  last_population: int64;
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
  min := 2500;
  max := -1;
  for i := 1 to n do
  begin
    if (cities[i].Get_year < min) and (cities[i].Get_name = name1) then
      min := cities[i].Get_year;
    if (cities[i].Get_year > max) and (cities[i].Get_name = name1) then
      max := cities[i].Get_year;
  end;
  if max = min then begin
    messageBox.Show('Одинаковые данные!', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.Error);
    button1.Enabled:=false;
    button2.Enabled:=false;
    exit;
  end;
  move := round(picturebox1.width / (max - min)) - 15;
  p := new Point(57, picturebox1.height - 15);
  pen1.Color := color.Blue;
  last_population := 0;
  //writeln(min,' ',max);
  for i := min to max do
  begin
    //writeln(i);
    if Is_found(i) then
      last_population := count(i);
    brush1.Color := color.blue;
    //writeln('last_population = ',last_population);
    graph.DrawRectangle(pen1, p.x, p.Y - 5 - 24 * (last_population div 100000), 30, 24 * (last_population div 100000));
    graph.FillRectangle(brush1, p.x, p.Y - 5 - 24 * (last_population div 100000), 30, 24 * (last_population div 100000));
    brush1.Color := color.Black;
    graph.DrawString(inttostr(i), myfont, brush1, p);
    p.x += move;
  end;
end;

function Is_found(y:int64):boolean;
var
  i:integer;
begin
  result:=false;
  for i:=1 to n do begin
    //writeln('Данные: ',cities[i].Get_year,' ', cities[i].Get_name,' ', cities[i].Get_population,' сравниваются с ',y,' ',name1);
    if (cities[i].Get_year = y) and (cities[i].Get_name = name1) then begin
      result:=true;
      break;
    end;
  end;
end;

function count(y: int64): int64;
begin
  result := 0;
  while (j <= n) do
  begin
    if (cities[j].Get_year = y) and (cities[j].Get_name = name1) then begin
      result := cities[j].Get_population;
      break;
    end;
    j += 1;
  end;
  if j < n then
    j += 1;
end;

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
end;

procedure Form1.label1_Click(sender: Object; e: EventArgs);
begin
  
end;

procedure Form1.label2_Click(sender: Object; e: EventArgs);
begin
  
end;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
var
  i: integer;
  key: boolean := false;
  s: string;
begin
  if (maskedtextbox1.Text = '') then exit;
  s := maskedtextbox1.Text;
  for i := 1 to length(s) do
    if s[i] in ['0'..'9'] then begin
      key := true;
      break;
    end;
  if key then begin
    messageBox.Show('Введено неверное название города', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.Error);
    exit;
  end;
  key:=false;
  for i:=1 to n do
    if cities[i].Get_name=s then begin
      key:=true;
      break;
    end;
  if not key then begin
    messageBox.Show('Данные не найдены', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.Error);
    exit;
  end;
  name1 := s;
  make_function();
  maskedtextbox1.Enabled := false;
end;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
begin
  pictureBox1.Image := nil;
  make_base();
  maskedtextbox1.Text := '';
  maskedtextbox1.Enabled := true;
  j := 1;
end;

end.
