#include<iostream>
#include<stack>
#include<string>
using namespace std;

void pushAtBottom(stack<int> &s, int x){
    if(s.empty()) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    pushAtBottom(s, x);
    s.push(temp);
}

string reverseString(string str) {
    string ans;
    stack<char> s;

    for(int i=0;i<str.size(); i++) {
        s.push(str[i]);
    }

    while(!s.empty()) {
        char top = s.top();
        ans += top;
        s.pop();
    }
    return ans;
}

void reverse(stack<int> &s) {
    if(s.empty()) {
            return;
    }

    int temp = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s, temp);
}

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void stockSpanProblem(vector<int> stock, vector<int> span) {
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for(int i=1;i<stock.size(); i++) {
        int currPrice = stock[i];
        while(!s.empty() && currPrice >= stock[s.top()]) {
            s.pop();
        }
        if(s.empty()) {
            span[i] = i+1;
        }else{
            int prevHigh = s.top();
            span[i] = i-prevHigh;
        }
    }
    for(int i=0;i<span.size();i++) {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main() {
    // stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);

    // pushAtBottom(s, 4);

    // while(!s.empty() ) {
    //     cout<<s.top() << " ";
    //     s.pop();
    // }

    // cout << endl;

    //reverse a string using stack
    // string str = "Hello World";
    // cout << "reverse = "<< reverseString(str) << endl;  

    //reverse a stack
    // stack<int> s;
    // s.push(3);
    // s.push(2);
    // s.push(1);
    // printStack(s);

    // reverse(s);
    // printStack(s);

    vector<int> stock = {100, 80, 60,70, 60, 85, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0}; // Initialize span vector with zeros
    stockSpanProblem(stock, span);  
    return 0;
} 