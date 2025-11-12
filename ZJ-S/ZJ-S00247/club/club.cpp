#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int N,A[maxn][3],cnt[4];
priority_queue<int> Hep[3];
void solve(){
    cin>>N;memset(cnt,0,sizeof cnt);int ans=0;
    for(int i=0;i<=2;i++){
        while(!Hep[i].empty()) Hep[i].pop();
    }
    for(int i=1;i<=N;i++){
        cin>>A[i][0]>>A[i][1]>>A[i][2];
        int id=0;
        if(A[i][1]>A[i][id]) id=1;
        if(A[i][2]>A[i][id]) id=2;
        cnt[id]++,ans+=A[i][id];
        int m=-1e9;
        for(int j=0;j<=2;j++) if(j!=id) m=max(m,A[i][j]-A[i][id]);
        Hep[id].push(m);
    }
    for(int i=0;i<=2;i++){
        while(Hep[i].size()>N/2) ans+=Hep[i].top(),Hep[i].pop();
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int T;cin>>T;while(T--) solve();
    return 0;
}