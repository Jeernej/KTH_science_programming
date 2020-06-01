function y=iterationIII(x,n)

y=x;

    if n==0  % stopping case when n has a value of 0  
        
        y=1;
        
    else
        
        i=1;
        
        while i < abs(n)
            
            y=y*x;
            i=i+1;
        end

        if n<0
            y=1/y;
            
        end
    end
end