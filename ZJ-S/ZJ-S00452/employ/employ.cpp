#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[505],b[505],c[505],jh[505],ans;
string s;
void dfs(int x,int s){
	if(x==n){
		if(s>=m)ans++;
		return;
	}
	if(s+n-x<m)return;
	for(int i=1;i<=n;i++){
		if(jh[i]==0){
			jh[i]=1;
			if(a[i]>=x&&b[x+1]==1)dfs(x+1,s+1);
			else dfs(x+1,s);
			jh[i]=0;
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s,s=" "+s;
	for(int i=1; i<=n; i++)b[i]=s[i]-'0';
	for(int i=1; i<=n; i++)cin>>a[i];
	dfs(0,0);
	cout<<ans<<"\n";
	return 0;
}
//csprp++;