function out=fromLast(arr,N)

if N<=0 || length(num2str(arr))<N
    disp('ERROR: N must be positive and smaller than length of a number')
else    
    N=N-1;
    y=num2str(arr);

out=str2num(y(length(y)-N))  ;

end
