// 简单来说就是一个反悔贪心
// 先全部按照最优化选择
// 然后看超过n/2的只有一种颜色
// 然后更换它即可
// 先写
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define fastio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
constexpr int N = 1e5+5;
int n;
struct Node{
    int val[4];
    int mx, secmx;  // idx
    int delta;
}nd[N];

struct CMP{
    bool operator ()(const int &n1, const int &n2)const{
        return nd[n1].delta > nd[n2].delta;
    }
};

inline void work(){
    cin >> n;
    LL ans=0;
    priority_queue<int,vector<int>,CMP> pri[4];
    for(int i=1; i<=n; i++){
        cin >> nd[i].val[1] >> nd[i].val[2] >> nd[i].val[3];
        nd[i].mx = nd[i].secmx= 0;
        for(int k=1; k<=3; k++){
            if(nd[i].val[k] >= nd[i].val[nd[i].mx]){
                nd[i].secmx = nd[i].mx;
                nd[i].mx = k;
            }
            else if(nd[i].val[k] >= nd[i].val[nd[i].secmx]){
                nd[i].secmx = k;
            }
        }
        nd[i].delta = nd[i].val[nd[i].mx] - nd[i].val[nd[i].secmx];
        ans += nd[i].val[nd[i].mx];
        pri[nd[i].mx].push(i);
    }
    // 只会有一个的priority_queue > n/2
    for(int i=1; i<=3; i++){
        while(pri[i].size() > n/2){
            int u = pri[i].top(); pri[i].pop();
            ans -= nd[u].delta;
        }
    }
    printf("%lld\n", ans);
    return ;
}

signed main(){
    fastio;
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)work();
    return 0;
}
