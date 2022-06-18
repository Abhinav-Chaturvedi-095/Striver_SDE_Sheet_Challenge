bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> s;
    for(int i=0;i<expression.size();i++){
        if(s.empty())
            s.push(expression[i]);
        else if(expression[i]==')' and s.top()=='(')
            s.pop();
        else if(expression[i]==']' and s.top()=='[')
            s.pop();
        else if(expression[i]=='}' and s.top()=='{')
            s.pop();
        else 
            s.push(expression[i]);
    }
    if(s.empty()) return true;
    return false;
}
