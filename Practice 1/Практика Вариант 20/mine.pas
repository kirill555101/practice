unit mine;

interface 

type
  City_File = record
    name: string[40];
    population, year: int64;
  end;
  
  city = class
  private
    name: string[40];
    population, year: int64;
  public
    procedure init(n: string; pop, y: int64);
    function Is_in_current_year(y: int64): boolean;
    function Is_millionaire(): boolean;
    function Is_equally(n: string; pop, y: int64): boolean;
    function Get_name(): string;
    function Get_population(): int64;
    function Get_year(): int64;
  end;

function input(): integer;
var
  f: file of City_File;
  cities: array[1..200] of city;

implementation

procedure city.init(n: string; pop, y: int64);
begin
  name := n; year := y; population := pop;
end;

function city.Is_in_current_year(y: int64): boolean;
begin
  if y = year then 
    result := true
  else
    result := false;
end;

function city.Is_millionaire(): boolean;
begin
  if (population >= 1000000) then
    result := true
  else
    result := false;
end;

function city.Is_equally(n: string; pop, y: int64): boolean;
begin
  if (name = n) and (population = pop) and (year = y) then
    result := true
  else
    result := false;
end;

function city.Get_name(): string;
begin
  result := name;
end;

function city.Get_population(): int64;
begin
  result := population;
end;

function city.Get_year(): int64;
begin
  result := year;
end;

function input(): integer;
var
  i: integer;
  f_read: City_File;
begin
  assign(f, 'file.dat');
  reset(f); 
  i := 1;
  while not (eof(f)) do
  begin
    read(f, f_read);
    cities[i] := new city;
    with f_read do
      cities[i].init(name, population, year);
    i += 1;
  end;
  result := i - 1;
  closefile(f);
end;

end.