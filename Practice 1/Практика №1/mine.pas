unit mine;

interface

type
  Product_File = record
    name: string[40];
    price: integer;
    production: integer;
    entry: string[20];
  end;
  
  product = class
  private
    name: string[40];
    price: integer;
    production: integer;
    entry: DateTime;
  public
    procedure init(n: string; price1: integer; prod: integer; entry1: DateTime);
    function Is_equally(pr_file: Product_File): boolean;
    function Get_Name(): string;
    function Get_Price(): integer;
    function Get_Production(): integer;
    function Get_Entry(): DateTime;
  end;

function input(): integer;
var
  f: file of Product_File;
  products: array[1..200] of product;

implementation

procedure product.init(n: string; price1: integer; prod: integer; entry1: DateTime);
begin
  name := n; price := price1; production := prod; entry := entry1;
end;

function product.Is_equally(pr_file: Product_File): boolean;
var 
en: DateTime;
begin
  en := Datetime.Parse(pr_file.entry);
  if (pr_file.name = name) and (pr_file.production = production) and (DateTime.Compare(entry, en) = 0) and (pr_file.price = price) then
    result := true
  else
    result := false;
end;

function product.Get_Name(): string;
begin
  result := name;
end;

function product.Get_Price(): integer;
begin
  result := price;
end;

function product.Get_Production(): integer;
begin
  result := production;
end;

function product.Get_Entry(): DateTime;
begin
  result := entry;
end;

function input(): integer;
var
  i: integer;
  pr_read: product_file;
  en: DateTime;
begin
  assign(f, 'file.dat');
  reset(f); 
  i := 1;
  while not (eof(f)) do
  begin
    read(f, pr_read);
    products[i] := new product;
    with pr_read do
    begin
      en := DateTime.Parse(entry);
      products[i].init(name, price, production, en);
    end;
    i += 1;
  end;
  result := i - 1;
  closefile(f);
end;

end.