#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+5;
const int mod=998244353;

int n,m;
bool vis[N];
int a[N],fac[N];
bool is_in[N];
ll ans;

void init(){fac[0]=1;for(int i=1;i<=N;i++)fac[i]=1ll*fac[i-1]*i%mod;}

void dfs(int x,int y){
	if(y>=m){
		ans=(ans+fac[n-x])%mod;
		return ;
	}
	if(x>=n)return ;
	for(int i=1;i<=n;i++){
		if(!is_in[i]){
			is_in[i]=1;
			dfs(x+1,y+(bool)(a[i]>y&&vis[x+1]));
			is_in[i]=0;
		}
	}

	return ;
}

void SOLVE(){
	init();
	scanf("%d%d",&n,&m);
	char c=getchar();
	while(c!='1' && c!='0')c=getchar();
	
	vis[1]=c-'0';
	for(int i=2;i<=n;i++)vis[i]=getchar()-'0';
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),printf("%d ",vis[i]);
	
	dfs(0,0); 
	printf("%lld\n",ans);
	
	return ;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int Test_time=1;
//	scanf("%d",&Test_time);
	while(Test_time--)SOLVE();
	return 0;
}
/*
*/
