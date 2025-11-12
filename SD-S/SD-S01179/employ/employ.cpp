#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,ans=0,a[505],vis[505],p[505];
string s;
void dfs(long long x){
	if(x>=n){
		int tg=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||tg>=a[p[i]]) tg++;
		}
		if(tg<=n-m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1,p[x+1]=i;
			dfs(x+1);
			vis[i]=0,p[x+1]=i;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vis[i]=1,p[1]=i;
		dfs(1);
		vis[i]=0,p[1]=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
