#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int main() {
    string exp;
    cin >> exp;

    stack<char> s;
    string ans;

    for (char ch : exp) {
        if (isalnum(ch)) {
            ans += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                ans += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop();
        }
        else {
            while (!s.empty() && s.top() != '(' &&
                   priority(s.top()) >= priority(ch)) {
                ans += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }

    cout << ans << endl;

    return 0;
}
