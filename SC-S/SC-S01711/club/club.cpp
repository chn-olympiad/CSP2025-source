#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005][5],p[5],ans,maxx;
void dfs(int x){
	if(x==n+1){
		maxx=max(ans,maxx);
		return;
	}
	for(int i=1;i<=3;i++){
		if(p[i]<n/2){
			p[i]++;
			ans+=a[x][i];
			dfs(x+1);
			p[i]--;
			ans-=a[x][i];
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(p,0,sizeof(p));
		maxx=-1;
		ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		dfs(1);
		printf("%d\n",maxx);
	}
	return 0;
}