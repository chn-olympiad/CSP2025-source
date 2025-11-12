//商峻熙 SN-J00227 西安市曲江第一中学 
#include <bits/stdc++.h> 
#define ll long long
using namespace std;
const int N = 5e3+10;
const int mod = 998244353;

ll red(){
	ll k = 0,f = 1;
	char c = getchar();
	while(c<'0' || c>'9'){
		if(c=='-')f = -1;
		c = getchar();
	}
	while(c>='0' && c<='9'){
		k = k*10+(c-'0');
		c = getchar();
	}
	return k*f;
}
int n,a[N];
ll ans = 0;
void dfs(int u,int num,int mx,int k){
	if(u > n){
		if(num>mx*2 && k>=3)ans = (ans+1)%mod;
		return;
	}
	dfs(u+1,num+a[u],max(mx,a[u]),k+1);
	dfs(u+1,num,mx,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n = red();
	for(int i = 1;i <= n;i++){
		a[i] = red();
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}
