function anyvalue()

U = input('enter infix expression : ','s');  %input is a string

init();
output=[];
k =1;
flag=0; % falg for thr numbers with multiple cifers

for i=1:length(U)
    
    if U(i) >= 48 && U(i) <=57 % ascii values of cifers [0,9]for U_i as an operand
        
        if flag==0
            output(k)=U(i); 
            % Transfer U_i to output
            output(k+1)=32; % ADD SPACE 32 ascii for space ' '
            k=k+2;
            flag=1; % set flag - if we do not get a cifer for next element we reset flag=0
        elseif flag==1 % we get a cifer aggain
            output(k-1)=U(i); % overwrite ' ' with new cifer
            output(k)=32;  % ADD NEW SPACE 
            k=k+1;
        end
    
    elseif U(i)=='('
        flag =0; % for operands we reset flag=0 
 
        push(U(i));
        
    elseif U(i)==')' % Pop symbols from stack and transfer them to output untill '('
        flag =0; % for operands we reset flag=0 

        while ~ismyempty()
            
            val=pop();
            
            if val=='('  % when pop is '('
                break; % break while
                
            else
                output(k)=val; % Transfer U_i to output
                output(k+1)=32; % ADD SPACE 32 ascii for space ' '
                k=k+2 ;
            end %if
        end %while

    elseif U(i)=='+' || U(i)=='-' || U(i)=='*' || U(i)=='/' 
        flag =0;

        while ~ismyempty() %do untill the stack is empty.
            
            t=peak(); % take a peak inside the stack
            
            if t~='('
                if p(t)<p(U(i)) %|| t=='(' || ismyempty()
                    break% break while loop if t is a left-paranthes
                end
            
            
            elseif t=='(' || ismyempty()
                break% break while loop if t is a left-paranthes
            
                
            else
                output(k)=t; % Transfer U_i to output
                output(k+1)=32; % ADD SPACE 32 ascii for space ' '
                k=k+2 ;
            end%if
            
            t=pop();
            
            if t ~='(' 
                output(k)=t ;% Transfer U_i to output
                 output(k+1)=32; % ADD SPACE 32 ascii for space ' '
                k=k+2 ;
               
            end
        end%while
        
        push(U(i));
    
    end
end % here the end of a infix input is reached 
        
while ~ismyempty() % empty whole stack
    output(k)=pop(); % Transfer U_i to output
    output(k+1)=32;
    k=k+2; 
end


disp('In RPN notation:');
disp(char(output));

disp('Result of evaluation:');
disp(evaluate_2(char(output)));

end
        
        
