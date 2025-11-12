#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10;
string s;
int n,m,a[N],b[N],vis[N],ans;
void dfs(int now){
	if(now>n){
		int got=0,fail=0;
		for(int i=1;i<=n;i++){
			if(fail>=b[i]){
				fail++;
				continue;
			}
			if(s[i-1]=='1') got++;
			else fail++;
		}
		if(got>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			b[now]=a[i];
			vis[i]=1;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
