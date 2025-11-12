#include<bits/stdc++.h>
using namespace std;
//40pts
const int Mod=998244353,N=5e3+5;
int n,a[N],ans,jmul[N];
void dfs(int now,int tot,int mx,int add){
	if(now==n+1){
		if(tot>=3){
			if(mx*2<add)ans=(ans+1)%Mod;
		}
		return;
	}
	dfs(now+1,tot+1,max(mx,a[now]),add+a[now]);
	dfs(now+1,tot,mx,add);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}
