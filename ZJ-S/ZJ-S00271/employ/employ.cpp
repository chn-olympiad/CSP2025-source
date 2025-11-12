#include<bits/stdc++.h>
#define ci const int
#define ri register int
using namespace std;
ci N=1e5+5,mod=998244353;
int n,m;
bool s[N],in[N];
long long ans;
void dfs(int x,int b=0,int sum=0){
	if(x>n){
		if(sum>=m) ans++;
	}
	for(int i=1;i<=n;++i){
		if(in[i]) continue;
		in[i]=1;
		int op=!s[x];
		dfs(x+1,b+op,op?sum+1:sum);
		in[i]=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d %d\n",&n,&m);
	for(ri i=1;i<=n;++i) s[i]=getchar()-'0';
	for(ri i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	dfs(0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}