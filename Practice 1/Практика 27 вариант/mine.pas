unit mine;

interface
type
  line_File=record
    name:string[40];
    year,number,length,count:integer;
  end;
  
  metroline=class
  private
    name:string[40];
    year,number,length,count:integer;
  public
    procedure init(n:string; y,num,l,c:integer);
    function Is_equally(l:line_File):boolean;
    function Get_average_length:real;
    function Get_name:string;
    function Get_year:integer;
    function Get_number:integer;
    function Get_length:integer;
    function Get_count:integer;
  end;
  
  function input():integer;
var
  f:file of line_File;
  lines:array[1..200] of metroline;

implementation

procedure metroline.init(n:string; y,num,l,c:integer);
begin
  name:=n; year:=y; number:=num; length:=l; count:=c;
end;

function metroline.Is_equally(l:line_File):boolean;
begin
  if (name=l.name) and (year=l.year) and (number=l.number) and (length=l.length) and (count=l.count) then
    result := true
  else
    result := false;
end;

function metroline.Get_average_length:real;
begin
  result:=length/count;
end;

function metroline.Get_name:string;
begin
  result:=name;
end;

function metroline.Get_year:integer;
begin
  result:=year;
end;

function metroline.Get_number:integer;
begin
  result:=number;
end;

function metroline.Get_length:integer;
begin
  result:=length;
end;

function metroline.Get_count:integer;
begin
  result:=count;
end;

function input():integer;
var
  i:integer;
  pr_read:line_file;
begin
  assign(f,'file.dat');
  reset(f); 
  i:=1;
  while not(eof(f)) do begin
    read(f,pr_read);
    lines[i]:=new metroline;
    with pr_read do
      lines[i].init(name,year,number,length,count);
    i+=1;
  end;
  result:=i-1;
  closefile(f);
end;

end.