class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto a: tokens){
            if( a=="+" || a=="-" || a=="*" ||a=="/"){
                long long int first=s.top();
                s.pop();
                long long int second=s.top();
                s.pop();
                if(a=="+"){
                    second=first+second;
                }
                else if(a=="-") {
                    second=second-first;
                }
                else if(a=="*"){
                    second=first*second;
                }
                else{
                    second=second/first;
                }
                s.push(int(second));
            }
            else{
                s.push(stoi(a));
            }
        }
        return s.top();
    }
};