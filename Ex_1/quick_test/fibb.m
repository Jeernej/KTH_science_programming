function out=fibb(n)

if n==1 || n==2
    
    out=1;
else
    
    out=fibb(n-1)+fibb(n-2);
    
end
    