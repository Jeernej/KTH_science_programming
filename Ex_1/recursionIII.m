function x = recursionIII(x,n)

    if n<0
        x=1/recursionIII(x,-n);
        
        
    elseif n==0  % stopping case when n has a value of 0  
        x=1;
                
    elseif n==1  % stopping case when n reaches value of one
        
        x;
        
    elseif n>1
        
%        x=x*x ;
        x=x*recursionIII(x,n-1); 
%        x=x*x ;
        
    end

end

    