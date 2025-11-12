#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 3;
int n, a[N][4];
int cnt[N], pos[N];
bool vis[N];

struct Item{
    int val, id, p;
    bool operator< (const Item &x)const{
        return val > x.val;
    }
};
vector<Item> tmp;

void solve(){
    tmp.clear();
    memset(cnt, 0, sizeof cnt), memset(vis, 0, sizeof vis), memset(pos, 0, sizeof pos);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 3; j++)
            cin >> a[i][j], tmp.push_back({a[i][j], i, j});
    sort(tmp.begin(), tmp.end());
    int tot = 0;
    for(int i = 1; i <= n * 3; i++){
        auto x = tmp[i - 1];
        if(vis[x.id])continue;
        tot += x.val, vis[x.id] = 1, cnt[x.p]++, pos[x.id] = x.p;
    }
    if(max({cnt[1], cnt[2], cnt[3]}) > n / 2){
        int id;
        if(cnt[1] > n / 2)id = 1;
        else if(cnt[2] > n / 2)id = 2;
        else id = 3;
        tmp.clear();memset(vis, 0, sizeof vis);
        for(int i = 1; i <= n; i++){
            if(pos[i] == id){
                for(int j = 1; j <= 3; j++)
                    if(id != j)tmp.push_back({a[i][j] - a[i][id], i, j});
            }
        }
        sort(tmp.begin(), tmp.end());
        int cur = 0;
        while(cnt[id] > n / 2){
            Item x = tmp[cur];cur++;
            if(vis[x.id])continue;
            tot += x.val, cnt[id]--, cnt[x.p]++, vis[x.id] = 1;
        }
    }
    printf("%lld\n", tot);
}

main(){
    freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int T;cin >> T;
    while(T--)solve();
}