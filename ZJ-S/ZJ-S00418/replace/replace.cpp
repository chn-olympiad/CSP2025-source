#include<bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 1e6 + 5;
typedef pair<string, string> PSS;

int n, q;
string s1, s2, t1, t2;
vector<PSS> v;

void dfs(string s) {

}

inline int read() {
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
    return x * f;
}

signed main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    n = read(), q = read();
    for(int i = 1; i <= n; i++) {
        cin >> s1 >> s2;
        v.emplace_back(s1, s2);
    }
    while(q--) {
        cin >> t1 >> t2;
        
    }
    return 0;
}