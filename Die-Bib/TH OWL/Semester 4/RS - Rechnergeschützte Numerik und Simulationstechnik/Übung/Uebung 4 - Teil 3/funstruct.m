function out = funstruct(varargin)

funhandle=@sin; result_struct='default'; value = 0;

for index = 1 : floor(nargin/2)
    switch varargin{index*2-1}
        case 'FunHandle',
            funhandle = varargin{index*2};
        case 'Value',
            value = varargin{index*2};
        case 'Struct',
            result_struct = varargin{index*2};
    end
end

result=feval(funhandle,value);
eval(['out.',result_struct,'=result;']);

end