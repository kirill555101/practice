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
    maskedTextBox4: MaskedTextBox;
    label4: &Label;
    maskedTextBox3: MaskedTextBox;
    label3: &Label;
    maskedTextBox2: MaskedTextBox;
    label2: &Label;
    maskedTextBox1: MaskedTextBox;
    button3: Button;
    label1: &Label;
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
  name1: string[40];
  price1: integer;
  production1: integer;
  entry1: string[20];
  pr_file: Product_File;
  c: string;
  i, n, j: integer;
  key: boolean := false;
begin
  if (maskedtextbox1.Text = '') or (maskedtextbox2.Text = '') or (maskedtextbox3.Text = '') or (maskedtextbox4.Text = '') then exit;
  name1 := maskedtextbox1.Text;
  entry1 := maskedtextbox2.Text;
  if (length(entry1) < 10) then begin
    messageBox.Show('Неверная форма времени. Укажите полную дату!', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.Error);
    exit;
  end;
  c := maskedtextbox3.Text;
  for i := 1 to length(c) do
    if (c[i] in ['a'..'z']) or (c[i] in ['A'..'Z']) or (c[i] in ['а'..'я']) or (c[i] in ['А'..'Я']) then begin
      messageBox.Show('Неверная форма записи цены. Она должна включать только цифры!', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.Error);
      exit;
    end;
  c := maskedtextbox4.Text;
  for i := 1 to length(c) do
    if (c[i] in ['a'..'z']) or (c[i] in ['A'..'Z']) or (c[i] in ['а'..'я']) or (c[i] in ['А'..'Я']) then begin
      messageBox.Show('Неверная форма записи объема партии. Она должна включать только цифры!', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.Error);
      exit;
    end;
  price1 := strtoint(maskedtextbox3.Text);
  production1 := strtoint(maskedtextbox4.Text);
  assign(f, 'file.dat');
  reset(f);
  n := input();
  with pr_file do begin
    name:=name1;
    price:=price1;
    production:=production1;
    entry:=entry1;
  end;
  for i := 1 to n do
  begin
    if products[i].Is_equally(pr_file) then begin
      key := true;
      for j := i to n - 1 do
        products[j] := products[j + 1];
      products[n] := nil;
      n -= 1;
      break;
    end;
  end;
  if key then
    messageBox.Show('Данные успешно удалены', 'Информация', MessageBoxButtons.OK, MessageBoxIcon.information)
  else begin
    messageBox.Show('Данные не найдены', 'Ошибка', MessageBoxButtons.OK, MessageBoxIcon.error);
    exit;
  end;
  assign(f, 'file.dat');
  rewrite(f);
  for i := 1 to n do
  begin
    with pr_file do
    begin
      name := products[i].Get_name;
      price := products[i].Get_Price;
      production := products[i].Get_Production;
      entry := products[i].Get_Entry.ToShortDateString;
    end;
    write(f, pr_file);
    products[i] := nil;
  end;
  closefile(f);
  maskedtextbox1.Text := '';
  maskedtextbox2.Text := '';
  maskedtextbox3.Text := '';
  maskedtextbox4.Text := '';
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
