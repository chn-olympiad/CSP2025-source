#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005][4];
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<pair<int, int>> q[4];
        for(int i = 1; i <= n; i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])q[1].push({-a[i][1], i});
            else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])q[2].push({-a[i][2], i});
            else if(a[i][3] >= a[i][2] && a[i][3] >= a[i][1])q[3].push({-a[i][3], i});
        }
        for(int i = 1; i <= 3; i++){
            vector<pair<int, int>> vec;
            while(!q[i].empty() && (int)q[i].size() + vec.size() > (n / 2)){
                int u = q[i].top().second;
                int w = -q[i].top().first;
                int id = -1, maxn = 0;
                for(int j = i + 1; j <= 3; j++){
                    if(a[u][j] > maxn){
                        maxn = a[u][j];
                        id = j;
                    }
                }
                if(id != -1){
                    q[i].pop();
                    q[id].push({-maxn, u});
                }
                else{
                    vec.push_back({w, u});
                    q[i].pop();
                }
            }
            for(auto &v : vec)q[i].push({-v.first, v.second});
            while(!q[i].empty() && (int)q[i].size() > (n / 2)){
                int u = q[i].top().second;
                int w = q[i].top().first;
                q[i].pop();
                int id = -1, maxn = 0;
                for(int j = i + 1; j <= 3; j++){
                    if(a[u][j] >= maxn){
                        maxn = a[u][j];
                        id = j;
                    }
                }
                if(id != -1)q[id].push({-maxn, u});
            }
        }
        int ans = 0;
        for(int i = 1; i <= 3; i++){
            while(!q[i].empty()){
                ans -= q[i].top().first;
                q[i].pop();
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
