
function sort=LAB_2()

% fileID = fopen('file.txt','r');
% global array = fscanf(fileID,'%d',[1 Inf]);
% fclose(fileID);

global array
array=[22, 36, 6, 79, 26, 45, 13, 31, 62, 27,27, 76, 33, 75,16, 47];

quicksort(1,length(array))

sort=array;

end


function quicksort(l,r)

% if r >= l
if r >l
    
    i = partition(l,r);
    
    quicksort(l,i-1);
    quicksort(i+1,r);
    
end %if

end


function out=partition(l,r)

%in the global vector array = arr!!!!
global array

p=floor((l+r)/2);  % Choose pivot at position p= (l + r) / 2
pivot=array(p); %in the global vector array = arr!!!!

last=array(r); % Exchange the pivot element with the last element (which is at position r)
array(r)=pivot;  % pivot to last
array(p)=last; % last to pivot

L=length(array);
k=1;
j=k;
for i=k:L   % Scan from left of the array
    
    if  array(i)>=pivot  % until an element greater than the pivot element is found (or the two pointers cross).
        ScLeft=array(i); % remember left element sepatately 
        
        for j=k:L % Scan from right of the array 
            
            if array(L-j)<pivot && i<=(L-j ) % until an element less than the pivot element is found (or the two pointers cross).
                %   If the position of the first element (the one greater than pivot) 
                %   is less than or ??equal?? to the position of the second element (less than pivot)
                
                array(i)=array(L-j);    % left is right
                array(L-j)= ScLeft;     % right is remembered left            
                k=j % remember right position         
                break
            end
            
            if i>=L-j %%  If the two pointers cross.
                break %for loop               
            end %if
            
            
        end %for
        
    end %if
    
    if i>=L-j %%  If the two pointers cross.
        break %for loop      
    end
    
end


if array(i)>array(r) % Exchange the pivot element and the element pointed to by the pointer if this element is greater than pivot
    array(r)=array(i);
    array(i)=pivot;
  
elseif array(i)<array(r) %if it is less, than exchange the pivot element with the element to the pointers right.   
    array(r)=array(i+1);
    array(i+1)=pivot;
    
end %if

out=i  %Return pivot position

% !!!!! Does the above algorithm work when you have multiple instances of the same element? 
% i guess it works

end
