function cheers(n)

    if n == 1  %stopping case when n reaches value of one
        disp('Hurray')
    else
        disp('Hip ')
        
    n=n-1 ;   
    cheers(n); % reccursion call of the same function

end 