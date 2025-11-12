#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#define ll long long
#define MOD 998244353
using namespace std;
const int N=510,S=(1<<18);
int n,m,c[N],f[2][S+10][20];
ll ans=0;
char s[N];
bool vis[N];
void dfs(int x,int k){
	if(k>n-m)return;
	if(x==n+1){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,k+((k>=c[i])||(s[x]=='0')));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
