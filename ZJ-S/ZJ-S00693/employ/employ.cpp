#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=100;
int n,m,i,ans,a[N],b[N],f[N];char s[N];
bool pd(){
	int x=0,sum=0;
	for(int i=1;i<=n;i++)
		if(x>=a[b[i]]||s[i]=='0') x++;
		else sum++;
	return sum>=m;
}
void dfs(int t){
	if(t==n+1){
		if(pd()) ans++,ans=ans%mod;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(f[i]==0){
			f[i]=1;b[t]=i;
			dfs(t+1);
			f[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s+1;
	for(i=1;i<=n;i++) cin>>a[i];
	if(n<=18){
		dfs(1);
		cout<<ans;
	}
	else{

	}
	return 0;
}
//20