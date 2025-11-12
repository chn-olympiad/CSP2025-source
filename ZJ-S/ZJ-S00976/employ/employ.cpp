#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],r[N],cnt,ans,l;
bool vis[N],aw[N];
char p[N];
void dfs(int x){
	if(x==n+1){
		cnt=n;
		memset(aw,0,sizeof aw);
		for(int i=1;i<=n;i++){
			if(aw[r[i]]) continue;
			if(p[i]=='0') cnt--;
			int now=0;
			for(int j=i+1;j<=n;j++){
				if(n-cnt>=c[r[j]]){
					aw[r[j]]=1;
					cnt--;
				}
			}
		}
		if(cnt>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		r[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++){
		p[i]=getchar();
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(1);
	printf("%d\n",ans);
	
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

