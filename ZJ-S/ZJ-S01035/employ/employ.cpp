#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505],ans=0,ma,ln,dp[505][505][505];
string s;
int c[15];
bool vis[505],test=1;
void dfs(int fl){
	if(fl==n){
		int sum=0,su=0;
		for(int i=0;i<fl;i++){
			if(s[i]=='0')su++;
			else if(a[c[i]]>su)sum++;
			else su++;
		}
		ma=max(ma,sum);
		if(sum>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		c[fl]=i;
		vis[i]=1;
		dfs(fl+1);
		vis[i]=0;
		c[fl]=0;
	}
}
long long f(){
	if(ln<m)return 0;
	int an=1;
	for(int i=1;i<=ln;i++){
		an=an*i%mod;
	}
	return an;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	ln=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(s[i-1]!='1')test=0;
		if(a[i]==0)ln--;
	}
	if(test)ans=f();
	else dfs(0);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/