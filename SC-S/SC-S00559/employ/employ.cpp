#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[505],cnt;
bitset<505>f,b;
long long ans,T=998244353;
void dfs(int x,int y){
	if(y>m)return;
	if(x>n){
		ans=(ans+1)%T;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			if(a[i]>y){
				if(!b[x]){
					dfs(x+1,y+1);
				}else{
					dfs(x+1,y);
				}
			}else{
				dfs(x+1,y+1);
			}
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&x);
		b[i]=x;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=20){
		m=n-m;
		dfs(1,0);
		printf("%lld",ans);
	}else{
		
	}
	return 0;
}