function sorted=shellsort(arr)

% arr=[1,7,3,2,0,5,0,8]; % input for lab Practice
% arr=[22, 36, 6, 79, 26, 45, 75, 13, 31, 62, 27, 76, 33, 16, 62, 47]
arr=[80,30,50,70,60,90,20,30,40]

i=1;
j=1;
h=1;
v=1;
h = 4;

while h <= length(arr)
    h=3*h+1;  % increase h while h <= length(arr)  
end

while h > 1
    
    h = floor(h/3);
    
    for i=(h+1):length(arr) 
        v = arr(i); % error comes from line 17 //Array indices must be positive !integers! or logical values.
        j = i;
    
        while arr(j-h) > v %&& (j-h)<=0 % error comes from (j-h)<0 //Array indices must be positive integers or logical values.

            arr(j) = arr(j-h);
            
            j = j-h;
            
            arr(j) = v;
%             h
           
            if (j-h)<=0 % now it woorks!!
%                 j
%                 h
%                 F=j-h
                break % break while when (j-h)<0
            end
               
        end               
    end    
end

end

