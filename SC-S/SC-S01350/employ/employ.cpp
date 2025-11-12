#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=998244353;
int n,m;
char c[510];
int r[510];
int use[510];
int ans=0;
int p[510];
int id[510][510];
void dfs(int x,int ct,int tot){
	if(ct>n-m+1)return;
//	cout<<x<<' '<<ct<<' '<<tot<<endl;
	if(x==n+1){
		if(tot>=m){
//			for(int i=1;i<=n;i++)cout<<p[i]<<' ';
//			cout<<endl;
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(use[i])continue;
		p[x]=i;
		use[i]=1;
		if(c[x]=='0'){
			dfs(x+1,ct+1,tot);
		}else{
//			if(x==3&&p[1]==1&&p[2]==3&&i==2)cout<<ct<<endl;
			if(ct>=r[i])dfs(x+1,ct+1,tot);
			else dfs(x+1,ct,tot+1);
		}
		use[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int pd=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]=='0')pd=0;
	}
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=n;j>=1;j--){
			id[i][j]=id[i+1][j];
			if(r[i]<=j){
				id[i][j]++;
			}
		}
	}
//	cout<<id[2][2]<<endl;
	dfs(1,0,0);
	
	cout<<ans<<endl;
	
//	if(pd){
//		int ans=1;
//		for(int i=1;i<=n;i++){
//			ans=(ans*i)%mod;
//		}
//		cout<<ans<<endl;
//		return 0;
//	}
	
	
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

18 0
110111101110011011
6 0 4 2 1 2 5 4 3 3 3 2 5 4 7 8 6 7


*/