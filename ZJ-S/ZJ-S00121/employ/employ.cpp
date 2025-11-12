/*

纯暴力骗分 8pts

*/

#include<bits/stdc++.h>
using namespace std;
int n, m;
int s[1000];
int c[1000];
int id[1000];
bool vis[1000];
int dfs(int d) {
    if(d == n + 1) {
        int sum = 0;
        for(int i = 1; i <= n; i ++) {
            if(s[i] == 0) {
                sum ++;
            } else {
                if(sum >= c[id[i]]) {
                    sum ++;
                }
            }
        }
        if(n - sum >= m) return 1;
        return 0;
    }
    int res = 0;
    for(int i = 1; i <= n; i ++) {
        if(vis[i]) continue;
        vis[i] = 1;
        id[d] = i;
        res += dfs(d + 1);
        vis[i] = 0;
    }
    return res;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        char c;
        cin >> c;
        s[i] = c - '0';
    }
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }
    cout << dfs(1) << "\n";
    return 0;
}