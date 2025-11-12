#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PLL;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
const ll N=1e5+5;

struct Node{
    int id1,id2;
    ll maxn,d;
    bool operator<(const Node &o) const {
        return maxn>o.maxn;
    }
}b[N];

int T,n;
ll a[N][5];

int cnt[5];
priority_queue<PLL> q[5];

void solve(){
    ll ans=0;
    for(int i=1;i<=3;i++){
        while(q[i].size()) q[i].pop();
        cnt[i]=0;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        b[i].id1=b[i].id2=0;
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
            if(!b[i].id1||a[i][b[i].id1]<=a[i][j]) b[i].id2=b[i].id1,b[i].id1=j;
            else if(!b[i].id2||a[i][b[i].id2]<=a[i][j]) b[i].id2=j;
        }
        b[i].maxn=a[i][b[i].id1];
        b[i].d=a[i][b[i].id2]-b[i].maxn;
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        ans+=b[i].maxn;
        cnt[b[i].id1]++;
        q[b[i].id1].push({b[i].d,i});
        if(cnt[b[i].id1]>n/2){
            ll d=q[b[i].id1].top().first;
            int idx=q[b[i].id1].top().second;
            ans+=d;
            cnt[b[idx].id1]--;
            cnt[b[idx].id2]++;
            q[b[i].id1].pop();
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--) solve();
}