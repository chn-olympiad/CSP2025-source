#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,m,a[510],b[510];
char s[510];
ll res;
bool check(){
	for(int i=1;i<=n;i++)if(s[i]!='1')return false;
	return true;
}
void dfs(int x,int sum){
	if(x==n+1){
		if(sum>=m)res++;
		return ;
	}
	if(sum+n-x+1<m)return;
	for(int i=1;i<=n;i++)if(!b[i]){
		b[i]=1;
		int su=sum;
		if(s[x]=='0')dfs(x+1,su);
		else if(x-1-sum>=a[i])dfs(x+1,su);
		else dfs(x+1,su+1);
		b[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>(s+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	if(check()){
		res=1ll;
		for(int i=2;i<=n;i++)res=(1ll*i*res)%mod;
		return cout<<res,0;
	}
	dfs(1,0);
	cout<<res;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
