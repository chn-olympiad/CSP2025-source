#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n,m;
int mod=998244353;
int p[1010],c[1010];
int ans=0;
int f[1010];
void dfs(int id,int lost){
	if(lost>n-m)return;
	if(id==n+1){
		ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++)if(!f[i]){
		f[i]=1;
		if(lost>=c[i]) dfs(id+1,lost+1);
		else dfs(id+1,lost+((p[id]+1)%2));
		f[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		p[i]=s[i-1]-'0';
	}
	dfs(1,0);
	cout<<ans<<"\n";
	return 0;
}