#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=25;

	int n,m,ans;
	string s;
	int c[MAXN],a[MAXN];
	
void dfs(int u){
	if(u>n){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]<cnt&&s[i-1]=='1')sum++;
			else if(s[i-1]=='0'||c[a[i]]>=cnt)cnt++;
		}
		if(sum>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		a[u]=i;
		dfs(u+1);
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans%998244353;
	return 0;
}
