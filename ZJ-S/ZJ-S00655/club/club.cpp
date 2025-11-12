#include<bits/stdc++.h>
using namespace std;
int t,n,p[5][100010],ans=-1;
void dfs(int lst,int k,int a,int b,int c,int sum){
	sum+=p[k][lst];
	if(lst==n){
		ans=max(ans,sum);
		return;
	}
	lst++;
	if(a<n/2)dfs(lst,1,a+1,b,c,sum);
	if(b<n/2)dfs(lst,2,a,b+1,c,sum);
	if(c<n/2)dfs(lst,3,a,b,c+1,sum);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int aaa=1;aaa<=t;aaa++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[1][i],&p[2][i],&p[3][i]);
		}
		dfs(1,1,1,0,0,0);
		dfs(1,2,0,1,0,0);
		dfs(1,3,0,0,1,0);
		printf("%d\n",ans);
		ans=-1;
	}
	return 0;
}
