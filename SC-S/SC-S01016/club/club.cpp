#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct node{
    int x[3];
}a[N];
int n;
int cnt[3];
vector<int>mem[3];
void solve(){
    cin>>n;
    memset(cnt,0,sizeof(cnt));
    for(auto i:{0,1,2})mem[i].clear();
    for(int i=1;i<=n;i++)for(auto j:{0,1,2})cin>>a[i].x[j];
    int ans=0;
    for(int i=1;i<=n;i++){
        int id=-1,mx=0;
        for(auto j:{0,1,2})if(a[i].x[j]>=mx)mx=a[i].x[j],id=j;
        ans+=mx,cnt[id]++,mem[id].push_back(i);
    }
    int lim=n/2;
    if(cnt[0]<=lim&&cnt[1]<=lim&&cnt[2]<=lim)return cout<<ans<<'\n',void();
    vector<int>vec,det;
    for(auto i:{0,1,2})if(cnt[i]>lim)vec=mem[i];
    int num=vec.size();
    for(auto i:vec){
        int id=-1,mx=0;
        for(auto j:{0,1,2})if(a[i].x[j]>=mx)mx=a[i].x[j],id=j;
        int mxx=0;
        for(auto j:{0,1,2})if(j!=id)mxx=max(mxx,a[i].x[j]);
        det.push_back(mx-mxx);
    }
    sort(det.begin(),det.end());
    for(int i=0;i<num-lim;i++)ans-=det[i];
    cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}