function sorted=buble3(arr)

% arr=[80,30,50,70,60,90,20,30,40];  % input for excercise 3
arr=[1,7,3,2,0,5,0,8];  % input for excercise 4

for j=1:length(arr)-1 % increase the number of bubbled elements
    
    i=1;

    while i<= length(arr)-j % go trough array until the bubbled element

        a=arr(i);

        if arr(i)>arr(i+1) % if next element is smaller

            arr(i)=arr(i+1); % swapping elements
            arr(i+1)=a; % swapping elements
            
        end

        i=i+1;

    end %while
end
    
sorted=arr;

end

