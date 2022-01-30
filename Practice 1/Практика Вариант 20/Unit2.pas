unit Unit2;

interface

uses System, System.Drawing, System.Windows.Forms, mine;

type
  Form1 = class(Form)
    procedure button2_Click(sender: Object; e: EventArgs);
    procedure button1_Click(sender: Object; e: EventArgs);
    procedure maskedTextBox1_MaskInputRejected(sender: Object; e: MaskInputRejectedEventArgs);
    procedure label4_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  private
    {$resource Unit2.Form1.resources}
    label1: &Label;
    label2: &Label;
    maskedTextBox2: MaskedTextBox;
    label3: &Label;
    maskedTextBox3: MaskedTextBox;
    button1: Button;
    button2: Button;
    maskedTextBox1: MaskedTextBox;
    {$include Unit2.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
    end;
  end;

implementation

uses unit1;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
begin
  form(new unit1.form1).Show;
  self.Close;
end;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
var
  c_file: City_File;
  i: integer;
  name1: string;
  population1, year1: int64;
  key: boolean := false;
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
  
  assign(f, 'file.dat');
  reset(f);
  Seek(f, FileSize(f));
  write(f, c_file);
  closefile(f);
  
  maskedtextbox1.Text := '';
  maskedtextbox2.Text := '';
  maskedtextbox3.Text := '';
end;

procedure Form1.maskedTextBox1_MaskInputRejected(sender: Object; e: MaskInputRejectedEventArgs);
begin
  
end;

procedure Form1.label4_Click(sender: Object; e: EventArgs);
begin
  
end;

end.
