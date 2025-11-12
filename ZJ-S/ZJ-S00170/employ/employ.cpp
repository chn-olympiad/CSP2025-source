#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,a[N],p[N],ans;
bool vis[N];
string s;
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(cnt>=a[p[i]]||s[i]=='0') cnt++;
		if(n-cnt>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;s=' '+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=10) dfs(1);
	cout<<ans<<'\n';
	return 0;
}
