function V2 = evaluate()

V = input('enter infix expression : ','s');

i = 1;

while i<= length(V)
    if V(i) >= 48 && V(i) <=57 % ascii values of cifers for U_i is an operand
        
        push(V(i)-48);
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
        %disp(a/b)
        push(a/b);
        
    end
    i=i+1;
end
    
disp(pop())   

end

        
        
        