#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=500;
const ll mod=998244353;
int n,m;
char s[N+5];
int c[N+5];
bool f[N+5];
ll ans;
void dfs(int x,int sum,int q){
	if(x==n){
		if(sum>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;	
		f[i]=1;
		if(c[i]>q&&s[x+1]=='1'){
			dfs(x+1,sum+1,q);
		}
		else dfs(x+1,sum,q+1);
		f[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	dfs(0,0,0);
	printf("%lld",ans);
	
	return 0;
}
