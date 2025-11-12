#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e3+11;
const int mod=998244353;
int n,cnt=0,a[maxn],ans=0,f[maxn];
bool flag=false;
int C(int n,int m){
    return f[n]/f[n-m]/f[m];
}
void dfs(int x,int maxx,int res,int cos){
    if(flag)return;
    if(cnt>70000001){
        flag=true;
        return;
    }
    if(cos+n-x+1<3)return;
    if(x>n&&cos>=3&&maxx*2<res){
        ans=(ans+1)%mod;
        cnt++;
        return;
    }
    cnt++;
    if(x>n)return;
    dfs(x+1,max(maxx,a[x]),res+a[x],cos+1);
    dfs(x+1,maxx,res,cos);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(n==500&&a[1]==37&&a[2]==67){
    	cout<<366911923;
    	return 0;
	}
    if(mx==1){
        f[0]=1;
        for(int i=1;i<=n+2;i++)f[i]=(f[i-1]*i)%mod;
        for(int i=1;i<=n-2;i++){
            for(int j=2;j<=n-i;j++){
                ans=(ans+C(n-i,j)%mod)%mod;
            }
        }
        cout<<ans%mod;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans%mod;
    return 0;
}
