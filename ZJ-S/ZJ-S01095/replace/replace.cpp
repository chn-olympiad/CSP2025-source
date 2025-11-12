#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<string, string> > vec;
int vis[200005];
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        string a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    while(m--){
        string s, t;
        cin >> s >> t;
        if(s.size() != t.size()){
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        int cnt = 0;
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < s.size(); i++){
            for(int j = 1; i + j - 1 < s.size(); j++){
                string a = s.substr(i, j);
                string b = t.substr(i, j);
                cnt = 0;
                for(auto &l : vec){
                    cnt++;
                    string d = l.second;
                    string c = s.substr(0, i - 1) + d + s.substr(i + j, s.size() - i - j);
                    if(a == l.first && c == t && !vis[cnt]){
                        ans++;
                        vis[cnt] = 1;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
