#include<bits/stdc++.h>
using namespace std;
const int N=105,mod=998244353;
int n,m,c[N];
long long fact[N],ans;
bool s[N],used[N];
void dfs(int d,int w){
	//printf("d:%d w:%d\n",d,w);
	if(w==m){
		ans=(ans+fact[n-d+1])%mod;
		return;
	}
	if(d>n)return;
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		used[i]=1;
		dfs(d+1,w+(s[d]&&d-w-1<c[i]));
		used[i]=0;
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++){
		char ch=getchar();
		s[i]=(ch!='0');
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	fact[0]=1;
	for(int i=1;i<=n;i++){
		fact[i]=(fact[i-1]*i)%mod;
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
