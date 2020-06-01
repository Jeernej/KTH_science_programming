function sorted=quick78(arr)
% Choose a pivot element.
% Elements less than the pivot go to the lower list.
% Elements greater than the pivot go to the higher list.
% Apply Quicksort to the sub-lists.
  
%  quick78([3, 1, 4, 1, 5, 9, 2, 6, 5, 3]) %input for excercise 7
%  quick78([22, 36, 6, 79, 26, 45, 75, 13, 31, 62, 27, 76, 33, 16, 62, 47])       %input for excercise 8

L=length(arr);
if L>1
    
    pivot=arr(ceil(L/2));
    lower=[];
    higher=[]; 
    PIVOT=[];
    
    for i=1:L %go trough the array and partition the list into a lower and a higher list
        
        if arr(i)<pivot
            
            lower=[lower,arr(i)];   % add to lower list
            
        elseif arr(i)>pivot
            
            higher=[higher,arr(i)]; % add to higher 
        
        elseif arr(i)==pivot
            
            PIVOT=[PIVOT,arr(i)];   % add to pivot
            
        end % if
    end % for sorting

    sorted=[quick78(lower),PIVOT,quick78(higher)];

elseif L==1 
    sorted=arr;

elseif L==0
    sorted=[];
    
end %if L>1

end

