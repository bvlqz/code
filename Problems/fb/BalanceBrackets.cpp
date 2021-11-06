bool isBalanced(string s) {
  std::stack<char> bracketStack; 
  
  for (int i = 0; i < s.size(); i ++)
  {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{')
    {
      bracketStack.push(s[i]);
    }
    else
    {
      char topItem = bracketStack.top();

      if ((s[i] == ')') && (topItem == '(')) bracketStack.pop();
      if ((s[i] == ']') && (topItem == '[')) bracketStack.pop();
      if ((s[i] == '}') && (topItem == '{')) bracketStack.pop();
    }    
  }
  return bracketStack.size() == 0; 
}
