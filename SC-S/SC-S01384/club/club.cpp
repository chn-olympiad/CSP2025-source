#include<bits/stdc++.h>
using namespace std;
int a[100007][5],go[4],n;
int t;
int dfs(int u){
	if(u>n)
		return 0;
	int maxx=-1;
	if(go[1]*2<n){
		go[1]++;
		maxx=max(maxx,dfs(u+1)+a[u][1]);
		go[1]--;
	}
	if(go[2]*2<n){
		go[2]++;
		maxx=max(maxx,dfs(u+1)+a[u][2]);
		go[2]--;
	}
	if(go[3]*2<n){
		go[3]++;
		maxx=max(maxx,dfs(u+1)+a[u][3]);
		go[3]--;
	}	
	return maxx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));memset(go,0,sizeof(go));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		printf("%d\n",dfs(1));
	}
	return 0;
}