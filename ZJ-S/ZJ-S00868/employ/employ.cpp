#include <bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
int n,m,c[505],a[505],vis[505];
string s;
long long ans;
long long jie(long long x){
    long long cnt=1;
    for(int i=1;i<=x;i++)cnt=1ll*cnt*i%Mod;
    return cnt;
}
void dfs(int k,int cnt){
    if(n-k+1+cnt<m)return;
    if(cnt>=m){
        ans=1ll*(ans+jie(n-k+1))%Mod;
        return;
    }
    if(k==n+1){
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        a[k]=i;
        vis[i]=1;
        if(cnt>k-1-c[i]&&s[k]=='1')dfs(k+1,cnt+1);
        else dfs(k+1,cnt);
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    sort(c+1,c+n+1);
    if(m==n){
        for(int i=1;i<=n;i++){
            if(s[i]=='0'){
                cout<<0;
                return 0;
            }
        }
        ans=1;
        int j=0;
        for(int i=1;i<=n;i++){
            while(j<n&&c[j+1]<i)j++;
            if(j<i){
                cout<<0;
                return 0;
            }
            ans=ans*1ll*(j-i+1ll)%Mod;
        }
        cout<<ans;
        return 0;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
