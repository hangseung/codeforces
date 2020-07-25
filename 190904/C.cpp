#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    int n;
    string str;
    stack<int> st;
    cin >> n >> str;
    
    int cnt = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str.at(i) == '(') {
            if (st.top() == 1 && cnt == 0) {
                if (st.empty()) {
                    st.push(0);
                    break;
                }
                st.pop();
                ++cnt;
            }
            else {
                st.push(0);
            }
        }
        else {
            if (st.top() == 0) {
                if (st.empty()) {
                    st.push(0);
                    break;
                }
                st.pop();
            }
            else {
                st.push(1);
            }
        }
    }
    
    if (st.size() == 0) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    
    return 0;
}