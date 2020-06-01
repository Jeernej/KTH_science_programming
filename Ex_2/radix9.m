function sorted=radix9(arr)

%   radix9([22, 36, 6, 79, 26, 45, 75, 13, 31, 62, 27, 76, 33, 16, 62, 47])     % input for excercise 9

N=length(num2str(max(arr))); % find length of the maximmum value of input array

box=[];
box0=[];
box1=[];
box2=[];
box3=[];
box4=[];
box5=[];
box6=[];
box7=[];
box8=[];
box9=[];

L=length(arr);

for j=1:N   
    
    for i=1:L %Place the numbers in boxes
        
        if (length(num2str(arr(i)))-j)<0  
            box=[box,arr(i)];
        elseif fromLast(arr(i),j)==0
            box0=[box0,arr(i)];
        elseif fromLast(arr(i),j)==1
            box1=[box1,arr(i)];
        elseif fromLast(arr(i),j)==2   
            box2=[box2,arr(i)];
        elseif fromLast(arr(i),j)==3   
            box3=[box3,arr(i)];
        elseif fromLast(arr(i),j)==4  
            box4=[box4,arr(i)];
        elseif fromLast(arr(i),j)==5  
            box5=[box5,arr(i)];
        elseif fromLast(arr(i),j)==6 
            box6=[box6,arr(i)];
        elseif fromLast(arr(i),j)==7  
            box7=[box7,arr(i)];
        elseif fromLast(arr(i),j)==8   
            box8=[box8,arr(i)];
        elseif fromLast(arr(i),j)==9           
            box9=[box9,arr(i)];     
        end
    end       

    arr=[box,box0,box1,box2,box3,box4,box5,box6,box7,box8,box9]; %Put the sublists together 
    
    box=[];
    box0=[];
    box1=[]; %empty boxes
    box2=[];
    box3=[];
    box4=[];
    box5=[];
    box6=[];
    box7=[];
    box8=[];
    box9=[];
    
    
sorted=arr;

end

