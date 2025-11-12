#include<bits/stdc++.h>
using namespace std;
int n,m,a[201],b[201];
long long ans,mod=998244353;
string ss;
void dfs(int c,int s,int tt){
	if(c==n){
		if(s>=m) ans+=1,ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!b[i]){
			b[i]=1;
			if(tt>=a[i]||ss[c]=='0') dfs(c+1,s,tt+1);
			else dfs(c+1,s+1,tt);
			b[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;cin>>ss;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
