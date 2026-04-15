function out = structgen(varargin)
for index = 1 : floor(nargin/2)
    switch varargin{index*2-1}
        case 'Name',
            out.Name = varargin{index*2};
        case 'Geburtsdatum',
            out.Geburtsdatum = varargin{index*2};
        case 'Beruf',
            out.Beruf = varargin{index*2};
    end
end
end