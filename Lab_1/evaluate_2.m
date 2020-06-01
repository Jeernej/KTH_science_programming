function out=evaluate_2(V)

%V = input('enter infix expression : ','s');

i = 1;
flag=0; % falg for the numbers with multiple cifers

while i<= length(V)
%   If V_i is an operand:    
%   Push V_i to stack
    
    if V(i) >= 48 && V(i) <=57 % ascii values of cifers for U_i is an operand
        if flag ==0
            push(V(i)-48);      
            flag=1; % set flag - if we do not get a cifer for next element we reset flag=0
        elseif flag==1
            temp=pop(); % we pop the first cifer 1 out
            newval=temp*10+V(i)-48; % we get 1*10+4=14 and we push 14 in
            push(newval); % we push 14 in
        end % if
        
    elseif V(i)==32 % acsii for ' '
       flag=0; % for ' ' we reset flag=0 
       
%   If V_i is an operator:     
%   Apply V_i to the top two elements of the stack. 
%   Replace these by the result in the stack.   

    elseif V(i)=='+'      
        a=pop();
        b=pop();
%         disp(a+b)
        push(a+b);     
    elseif V(i)=='-' 
        a=pop();
        b=pop();
%         disp(a-b)
        push(a-b);
    elseif V(i)=='*' 
        a=pop();
        b=pop();
%         disp(a*b)
        push(a*b);
    elseif V(i)=='/' 
        a=pop();
        b=pop();
%        disp(a/b)
        push(a/b);       
    end
    i=i+1;
end
    
%disp(pop())   
out=pop();
end

        
        
        