function recursionII(x,n)

    if n<0
        disp('input "n" has to be a positive number') 
        
    elseif n==0  % stopping case when n has a value of 0  
        disp('1')
                
    elseif n==1  % stopping case when n reaches value of one
        disp(x)
        
    elseif n>1
        x*recursionIII(x,n-1)
  
        
end      
