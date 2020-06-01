function sorted=select3(arr)

% arr=[80,30,50,70,60,90,20,30,40];  % input for excercise 3
arr=[1,7,3,2,0,5,0,8];  % input for excercise 4

for j=1:length(arr)-1 % increase sorted part
    
    i=j;
    k=j;
    a=arr(j); %remember first unsorted value
    
    while i< length(arr) % go trough  unsorted part

        if a>arr(i+1)

            a=arr(i+1); % forget him and take guy one instead, he was to big for you anyway
            k=i+1;  % remember where you guys met
            
        end %if

        i=i+1;
        
    end %while
    %swap values at j and k 
    arr(k)=arr(j);  % write first unsorted value to  position of the smallest value
    arr(j)=a; % write the smallest value to position of first unsorted value
end %for
    
sorted=arr;

end