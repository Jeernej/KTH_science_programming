function quicksort(l,r)

% if r >= l
if r > l
    
    i = partition(l,r);
    
    quicksort(l,i-1);
    quicksort(i+1,r);
    
end %if

end
