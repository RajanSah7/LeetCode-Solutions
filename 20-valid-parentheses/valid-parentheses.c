

bool isValid(char* s) {
    int n, i;
    n = strlen(s);
    char stack[n];
    int top = -1;
    
    for(i = 0; i < n; i++) {
        char c = s[i];
        if(c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        else if(c == ')' || c == '}' || c == ']') {
            if(top == -1) {
                return false;
            }
            
            char prev = stack[top--];
            
            if(c == ')' && prev != '(') return false;
            if(c == '}' && prev != '{') return false;
            if(c == ']' && prev != '[') return false;
        }
    }
    return top == -1;
}