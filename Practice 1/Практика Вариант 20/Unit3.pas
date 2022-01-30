unit Unit3;

interface

uses System, System.Drawing, System.Windows.Forms, mine;

type
  Form1 = class(Form)
    procedure button1_Click(sender: Object; e: EventArgs);
    procedure button2_Click(sender: Object; e: EventArgs);
    procedure button3_Click(sender: Object; e: EventArgs);
    procedure maskedTextBox1_MaskInputRejected(sender: Object; e: MaskInputRejectedEventArgs);
    procedure label4_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit3.Form1.resources}
    button2: Button;
    button1: Button;
    maskedTextBox3: MaskedTextBox;
    label3: &Label;
    maskedTextBox2: MaskedTextBox;
    label2: &Label;
    maskedTextBox1: MaskedTextBox;
    label1: &Label;
    button3: Button;
    {$include Unit3.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
    end;
  end;

implementation

uses unit1;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
var
  c_file: City_File;
  i, j, n: integer;
  name1: string;
  population1, year1: int64;
  key: boolean := false;
  key1: boolean := false;
begin
  if (maskedtextbox1.Text = '') or (maskedtextbox2.Text = '') or (maskedtextbox3.Text = '') then exit;
  name1 := maskedtextbox1.Text;
  population1 := strtoint64(maskedtextbox2.Text);
  year1 := strtoint64(maskedtextbox3.Text);
  for i := 1 to length(name1) do
    if name1[i] in ['0'..'9'] then begin
      key := true;
      break;
    end;
  if key then begin
    messageBox.Show('Введено неверное название города', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.Error);
    exit;
  end;
  with c_file do
  begin
    name := name1;
    population := population1;
    year := year1;
  end;
  
  n := input();
  for i := 1 to n do
  begin
    if cities[i].Is_equally(c_file.name, c_file.population, c_file.year) then begin
      key1 := true;
      for j := i to n - 1 do
        cities[j] := cities[j + 1];
      cities[n] := nil;
      n -= 1;
      break;
    end;
  end;
  if key1 then
    messageBox.Show('Данные успешно удалены', 'Информация', MessageBoxButtons.OK, MessageBoxIcon.information)
  else begin
    messageBox.Show('Данные не найдены', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.error);
    exit;
  end;
  
  assign(f, 'file.dat');
  rewrite(f);
  for i := 1 to n do
  begin
    with c_file do
    begin
      name := cities[i].Get_name;
      population := cities[i].Get_population;
      year := cities[i].Get_year;
    end;
    write(f, c_file);
    cities[i] := nil;
  end;
  closefile(f);
  
  maskedtextbox1.Text := '';
  maskedtextbox2.Text := '';
  maskedtextbox3.Text := '';
end;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
begin
  form(new unit1.form1).Show;
  self.Close;
end;

procedure Form1.button3_Click(sender: Object; e: EventArgs);
begin
  assign(f, 'file.dat');
  rewrite(f);
  closefile(f);
  messageBox.Show('Данные успешно удалены', 'Информация', MessageBoxButtons.OK, MessageBoxIcon.information)
end;

procedure Form1.maskedTextBox1_MaskInputRejected(sender: Object; e: MaskInputRejectedEventArgs);
begin
  
end;

procedure Form1.label4_Click(sender: Object; e: EventArgs);
begin
  
end;

end.
