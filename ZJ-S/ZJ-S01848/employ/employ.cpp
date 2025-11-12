#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,pl[510],mod=998244353,ans,f[510],c[510],p[510];
string s;
void dfs(int t,int num,int sum){
	if(sum+n-t+1<m)return ;
	if(sum>=m){
		ans+=pl[n-t+1];
		ans%=mod;
		return ;
	}
	if(t>n){
//		if(sum>=m)ans++;ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(f[i]==0){
			f[i]=1;
			p[t]=i;
			if(num>=c[i]||s[t-1]=='0')dfs(t+1,num+1,sum);
			else dfs(t+1,num,sum+1);
			f[i]=0;
		}
}
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	pl[0]=1;
	for(int i=1;i<=n;i++)
		pl[i]=pl[i-1]*i%mod;
	sort(c+1,c+1+n,cmp);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
10pts
*/
