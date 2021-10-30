disp("Cohen Sutherland Line Clipping Algorithm");
%To take the input from the user
x1 = input("Enter the value x1 coordinate for line ");
y1 = input("Enter the value y1 coordinate for line ");
x2 = input("Enter the value x2 coordinate for line ");
y2 = input("Enter the value y2 coordinate for line ");

% Region Codes for different regions
bottom = 4;
top = 8;
left = 1;
right = 2;
inside = 0;


% Defining x_max, x_min, y_max, y_min for line clipping
x_max = 12;
y_max = 10;
x_min = 6;
y_min = 6;

c1 = generateCode(x1,y1);
c2 = generateCode(x2,y2);

accept = false;
x=0;
y=0;

if ((c1 | c2) == 0)
    accept = true;
elseif ((c1 & c2)~= 0)
    accept = false;
else
    accept = true;
    if (c1 ~= 0)
        code_out = c1;
    else
        code_out = c2;
    end
    
    if(code_out & top)
        x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
        y = y_max;
    elseif (code_out & bottom)
         x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
         y = y_min;
    elseif (code_out & left)
         y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
         x = x_min;
    elseif (code_out & right)
         y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
         x = x_max;
    end
    
    if(code_out == c1)
        x1=x;
        y1=y;
    elseif (code_out == c2)
        x2=x;
        y2=y;
    end
end

if(accept==true)
    disp(x1+","+y1+" to "+x2+","+y2);
else
    disp("Line is rejected");
end
function code = generateCode(x,y)

    inside = 0000;
    top = 1000;
    bottom = 0100;
    left = 0010;
    right = 0001;

    x_max = 12;
    y_max = 10;
    x_min = 6;
    y_min = 6;
    
    int_code = inside;
    
    if (x < x_min) 
        int_code = int_code|left;
    elseif (x > x_max) 
        int_code = int_code|right;
    end
    
    if (y < y_min) 
        int_code = int_code|bottom;
    elseif (y > y_max) 
        int_code = int_code|top;
    end
    code = int_code;
end
