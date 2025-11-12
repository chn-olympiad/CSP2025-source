#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 15;
int n,a[N][3];
vector<pair<int,int>> vec[3];
void solve(){
    cin >> n;
    vec[0].clear();
    vec[1].clear();
    vec[2].clear();
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < 3;j ++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        static int p[3];
        iota(p,p + 3,0);
        sort(p,p + 3,[&](const int f,const int g){
            return a[i][f] > a[i][g];
        });
        vec[p[0]].push_back({i,a[i][p[0]] - a[i][p[1]]});
        ans += a[i][p[0]];
    }
    if(vec[0].size() > n / 2){
        sort(vec[0].begin(),vec[0].end(),[&](const pair<int,int> f,const pair<int,int> g){
            return f.second < g.second;
        });
        for(int i = 0;i < vec[0].size() - n / 2;i ++){
            ans -= vec[0][i].second;
        }
    }
    if(vec[1].size() > n / 2){
        sort(vec[1].begin(),vec[1].end(),[&](const pair<int,int> f,const pair<int,int> g){
            return f.second < g.second;
        });
        for(int i = 0;i < vec[1].size() - n / 2;i ++){
            ans -= vec[1][i].second;
        }
    }
    if(vec[2].size() > n / 2){
        sort(vec[2].begin(),vec[2].end(),[&](const pair<int,int> f,const pair<int,int> g){
            return f.second < g.second;
        });
        for(int i = 0;i < vec[2].size() - n / 2;i ++){
            ans -= vec[2][i].second;
        }
    }
    cout << ans << '\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;cin >> T;
    while(T --) solve();
    return 0;
}
/*
too difficult greedy
*/