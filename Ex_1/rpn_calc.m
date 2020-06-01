function rpn_calc(U)

stack=[]
output=[]

for i=1 in U
    
    if Ui== '0123456789'  %U_i is an operand: Transfer U_i to output  
        
        output[i]=Ui

    if Ui=='('            %U_i is a left paranthes: Push U_i to stack
        
        push(stack,Ui)

    if Ui==')' %U_i is a right paranthes: 
                %Pop symbols from stack and transfer them to output until a left-paranthes is met. 
                % Pop left-paranthes.
                
        for j=1 in stack 
            
            X=pop(stack)
            
            if X==')'
                pop(stack)
                break        
                
            else
                output[i]=X
            
                
    if Ui=='+-*/'  %U_i is an operator: Let the top stack element be t. 
        
                    %Pop and transfer symbols from stack to output until:
                    %p(t) < p(U_i) or t is a left-paranthes or
                    %the stack is empty.Push U_i to the stack
                    
        for j=1 in stack 
            
            X=pop(stack)
            
            if X==')'
                pop(stack)
                break        
                
            else
                output[i]=X        
        
%Transfer the remaining symbols in stack to output

    disp('RPN notation:')
    disp(output)

    
    
    
    disp('Result of evaluation:')
    disp(result)


end