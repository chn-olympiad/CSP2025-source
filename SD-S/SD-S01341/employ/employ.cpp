#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
const int mod = 998244353,N = 500;
ll fac[N],ans;
int n,m,fl[N],c[N];
char s[N+5];
bool vis[N];
void init(){
	fac[0] = 1;
	for(int i = 1;i <= n;i++)
		fac[i] = (fac[i-1]*i)%mod;
}
void dfs(int x,int p,int f){
	if(p >= m){
		ans = (ans+fac[n-x])%mod;
		return;
	}
	if(x > n){
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i])
			continue;
		vis[i] = true;
		if(s[x] == '0')
			dfs(x+1,p,f);
		else if(fl[x] + f >= c[i])
			dfs(x+1,p,f+1);
		else
			dfs(x+1,p+1,f);
		vis[i] = false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	init();
	scanf("%s",&s);
	int can = 0;
	for(int i = 1;i <= n;i++){
		fl[i] = fl[i-1];
		if(s[i-1] == '0')
			fl[i]++;
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&c[i]);
		if(c[i] != 0)
			can++;
	}
	if(can < m){
		printf("0\n");
		return 0;
	}
	if(fl[n] == 0){
		printf("%lld\n",fac[n]%mod);
		return 0;
	}
	dfs(0,0,0);
	printf("%lld\n",ans);
	return 0;
}

