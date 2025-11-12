#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
constexpr int N=1e5+5;
int n,ans;
struct Data {
    int v[3],d[3];
} a[N];
bool cmp(Data &x,Data &y) {
    if(x.v[x.d[0]]-x.v[x.d[1]]!=y.v[y.d[0]]-y.v[y.d[1]]) return x.v[x.d[0]]-x.v[x.d[1]]>y.v[y.d[0]]-y.v[y.d[1]];
    else return x.v[x.d[1]]-x.v[x.d[2]]>y.v[y.d[1]]-y.v[y.d[2]];
}
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].v[0]>>a[i].v[1]>>a[i].v[2];
    ans=0;
    for(int i=1;i<=n;i++) {
        int mx[3]={-1,-1,-1};
        for(int j=0;j<3;j++) {
            if(a[i].v[j]>mx[0]) mx[1]=mx[0],a[i].d[1]=a[i].d[0],mx[0]=a[i].v[j],a[i].d[0]=j;
            else if(a[i].v[j]>mx[1]) mx[1]=a[i].v[j],a[i].d[1]=j;
        }
        a[i].d[2]=3-a[i].d[0]-a[i].d[1];
    }
    sort(a+1,a+n+1,cmp);
    int cnt[3]={0,0,0};
    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) {
            if(cnt[a[i].d[j]]<n/2) {
                ans+=a[i].v[a[i].d[j]];
                cnt[a[i].d[j]]++;
                break;
            }
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}