#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=998244353;
int n,m,ans;
bool s[505];
int c[505];
bool flag=1;
int l[505];
bool vis[505];
void dfs(int step){
    if(step>n){
        int sum=0;
        for(int i=1;i<=n;i++){
            int now=c[l[i]];
            if(sum>=now||s[i]==0){
                sum++;
            }
        }
        if(n-sum>=m){
            ans++;
            ans%=mod;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        l[step]=i;
        vis[i]=1;
        dfs(step+1);
        vis[i]=0;
    }
}
signed main(){
    //freopen("employ2.in","r",stdin);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        s[i]=x-48;
        if(x=='0') flag=0;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(flag){
        ans=1;
        for(int i=1;i<=n;i++){
            ans=(ans*n)%mod;
        }
    }else dfs(1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
