function y=iterationII(x,n)

y=x;
    if n<0
        disp('input "n" has to be a positive number') 
        
    elseif n==0  % stopping case when n has a value of 0  
        disp('1')
 

    else
        
        i=1;
        
        while i < n
            
            y=y*x;
            i=i+1;
        end
            
end

