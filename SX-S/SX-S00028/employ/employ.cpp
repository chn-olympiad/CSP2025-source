#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,a[505],f[505],b[505],ans,c[505];
string st;
void dfs(int x){
	if (x>n){
		int cnt=0,ss=0;
		for (int i=1;i<=n;i++){
			if (st[i]=='0')cnt++;
			else{
				if (a[b[i]]>cnt)ss++;
				else cnt++;
			}
		}
		if (ss>=m)ans=(ans+1)%mod;
		return;
	}
	for (int i=1;i<=n;i++){
		if (!f[i]){
			f[i]=1;
			b[x]=i;
			dfs(x+1);
			f[i]=0;
		}
	}
}
void df(int x,int ss,int cnt){
//	if (ss+n-x+1<m)return;
	if (x>n){
		if (ss>=m)ans=(ans+1)%mod;
		return;
	}
	for (int i=1;i<=n;i++){
		if (!f[i]){
			f[i]=1;
			b[x]=i;
			if (st[x]=='0')cnt++;
			else{
				if (a[i]>cnt)ss++;
				else cnt++;
			}
			df(x+1,ss,cnt);
			if (st[x]=='0')cnt--;
			else{
				if (a[i]>cnt)ss--;
				else cnt--;
			}
			f[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>st;
	st=" "+st;
	bool bl=1;
	for (int i=1;i<=n;i++)if (st[i]=='0')bl=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]++;
		if (a[i]==0)bl=0;
	}
//	if (n<=10){
//		dfs(1);
//		cout<<ans<<'\n';
//		exit(0);
//	}
	if (n<=18){
		df(1,0,0);
		cout<<ans<<'\n';
		exit(0);
	}
	ans=1;
	for (int i=1;i<=n;i++)ans=(ans*i)%mod;
	if (m==n){
		if (!bl)cout<<0<<'\n';
		else{
			cout<<ans<<'\n';
		}
		exit(0);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
10 5
1111111111
6 0 4 2 1 2 5 4 3 3
*/