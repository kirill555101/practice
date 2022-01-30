unit mine;

interface
type
  Pricelist_File=record
    service:string[40];
    days:integer;
    surname:string[40];
    price:integer;
  end;
  
  pricelist=class
  private
    service:string[40];
    days:integer;
    surname:string[40];
    price:integer;
  public
    procedure init(serv:string;d:integer;sur:string;pr:integer);
    function Get_Service():string;
    function Get_Days():integer;
    function Get_Surname():string;
    function Get_Price():integer;
    function Is_Equally(pr_file:Pricelist_File):boolean;
  end;
  
  function input():integer;
var
  f:file of Pricelist_File;
  lists:array[1..200] of pricelist;

implementation

procedure pricelist.init(serv:string;d:integer;sur:string;pr:integer);
begin
  service:=serv; days:=d; surname:=sur; price:=pr;
end;

function pricelist.Get_Service():string;
begin
  result:=service;
end;

function pricelist.Get_Days():integer;
begin
  result:=days;
end;

function pricelist.Get_Surname():string;
begin
  result:=surname;
end;

function pricelist.Get_Price():integer;
begin
  result:=price;
end;

function pricelist.Is_Equally(pr_file:Pricelist_File):boolean;
begin
  if (pr_file.service = service) and (pr_file.days = days) and (pr_file.surname = surname) and (pr_file.price = price) then
    result:=true
  else
    result:=false;
end;

function input():integer;
var
  i:integer;
  pr_read:Pricelist_File;
begin
  assign(f,'file.dat');
  reset(f); 
  i:=1;
  while not(eof(f)) do begin
    read(f,pr_read);
    lists[i]:=new pricelist;
    with pr_read do
      lists[i].init(service,days,surname,price);
    i+=1;
  end;
  result:=i-1;
  closefile(f);
end;

end.