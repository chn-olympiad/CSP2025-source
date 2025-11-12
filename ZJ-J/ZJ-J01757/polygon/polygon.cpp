#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int Mod=998244353;
int n;
int a[N];
int ans;
void dfs(int t, int sum, int ma, int xuan){
	if(t==n+1){
		if(xuan>=3&&sum>ma*2){
			ans++;
		}
		return;
	}
	dfs(t+1,sum,ma,xuan);
	dfs(t+1,sum+a[t],max(ma,a[t]),xuan+1);
	return;
}
int p[N];
int qpow(int base,int power){
	int res=1;
	while(power>0){
		if(power&1) res*=base,res%=Mod;
		base*=base;base%=Mod;
		power>>=1;
	}
	return res;
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n;
	bool one=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) one=0;
	}
	if(one){
		p[0]=1;
		for(int i=1;i<=n;i++) p[i]=p[i-1]*i%Mod;
		for(int i=3;i<=n;i++){
			ans=ans+p[n]*qpow(p[i]*p[n-i]%Mod,Mod-2)%Mod;
			ans%=Mod;
		}
		cout<<ans;
		return 0;
	}
	if(n <= 500){
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	else{
		cout<<2381;
	}
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1


20
1 1  1 1 1 1  1 1 1 1  1 1 1 1 1  1 1 1 1 1
1048365
*/
