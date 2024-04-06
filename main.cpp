#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        const int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                if(!st.empty()) st.pop();
                else s[i] = '*';
            }
        }
        while (!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());

        return s;
    }
};

int main() {
    Solution s;
    string s1 = "))((";
    cout << s.minRemoveToMakeValid(s1);
    return 0;
}
