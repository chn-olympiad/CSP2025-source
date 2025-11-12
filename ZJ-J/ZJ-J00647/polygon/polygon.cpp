#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int N=5010;
int n,a[N];
ll res;
vector<int> c;
void calc(){
    int len=c.size();
    if(len<3) return;
    int sum=0;
    for(auto i:c) sum+=i;
    if(sum>c[len-1]*2) res=(res+1)%mod;
}
void dfs(int st){
    calc();
    for(int i=st;i<=n;++i){
        c.push_back(a[i]);
        dfs(i+1);
        c.pop_back();
    }
}
ll sum[N];
int mx[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
    if(n<=20){
        dfs(1);
        cout<<res<<"\n";
        return 0;
    }
    vector<ll> f(sum[n]+1,0),g(sum[n]+1,0);
    f[0]=g[0]=1;
    for(int i=1;i<=n;++i){
        if(i>2) res=(res+f[a[i]+1])%mod;
        for(int j=0;j<=sum[i];++j){
            g[j]=(f[j]+f[max(j-a[i],0)])%mod;
        }
        f=g;
    }
    cout<<res<<"\n";
    return 0;
}