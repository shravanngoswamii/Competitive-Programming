//ChatGPT Generated

#include<bits/stdc++.h>

using namespace std;

const int MAX_LENGTH = 400;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        char str[MAX_LENGTH];
        cin >> str;
        stack<char> st;
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            if (str[i] == '(')
                st.push(str[i]);
            else if (str[i] == ')') {
                char ch = st.top();
                st.pop();
                st.pop();
                cout << ch;
            } else if (isalpha(str[i]))
                cout << str[i];
            else
                st.push(str[i]);
        }
        cout << endl;
    }
    return 0;
}


/*
Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*

https://www.spoj.com/problems/ONP/
*/