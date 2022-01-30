unit mine;

interface
type
  date=record
    day:integer;
    month:integer;
    year:integer;
  end;
  
  Product_File=record
    name:string[40];
    release:date;
    company:string[40];
    memory:integer;
  end;
  
  product=class
  private
    name:string[40];
    release:date;
    company:string[40];
    memory:integer;
  public
    procedure init(n:string;rel:date;comp:string;mem:integer);
    function Is_enough_memory(mem:integer):boolean;
    function Is_released_in_period(comp:string;first,last:integer):boolean;
    function Get_name:string;
    function Get_release_date:date;
    function Get_company_name:string;
    function Get_memory:integer;
    function Is_equally(pr_file:Product_File):boolean;
  end;
  
  function input():integer;
var
  f:file of Product_File;
  products:array[1..200] of product;

implementation

procedure product.init(n:string;rel:date;comp:string;mem:integer);
begin
  name:=n; release:=rel; company:=comp; memory:=mem;
end;

function product.Is_enough_memory(mem:integer):boolean;
begin
  if (memory<=mem) then
    result := true
  else
    result := false;
end;

function product.Is_released_in_period(comp:string;first,last:integer):boolean;
begin
  if (company=comp) and (first<=release.year) and (release.year<=last) then
    result := true
  else
    result := false;
end;

function product.Get_name:string;
begin
  result:=name;
end;

function product.Get_release_date:date;
begin
  result:=release;
end;

function product.Get_company_name:string;
begin
  result:=company;
end;

function product.Get_memory:integer;
begin
  result:=memory;
end;

function product.Is_equally(pr_file:Product_File):boolean;
begin
  if (pr_file.name=name) and (pr_file.memory=memory) and (pr_file.company=company) and (pr_file.release=release) then
    result := true
  else
    result:=false;
end;

function input():integer;
var
  i:integer;
  pr_read:product_file;
begin
  assign(f,'file.dat');
  reset(f); 
  i:=1;
  while not(eof(f)) do begin
    read(f,pr_read);
    products[i]:=new product;
    with pr_read do
      products[i].init(name,release,company,memory);
    i+=1;
  end;
  result:=i-1;
  closefile(f);
end;

end.