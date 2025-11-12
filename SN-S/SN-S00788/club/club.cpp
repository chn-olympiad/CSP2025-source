#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int t,n,tmp[5],ans=-1,le[N][5],x;
void dfs(int i,int fen){
	if(i>n){
		ans=max(ans,fen);
		return ;
	}
	for(int j=1;j<=3;j++)
	    if(tmp[j]<x){
	    	tmp[j]+=1;
	    	dfs(i+1,fen+le[i][j]);
	    	tmp[j]-=1;
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=-1;
		cin>>n;x=n/2;
		for(int i=1;i<=n;i++)
		    scanf("%d%d%d",&le[i][1],&le[i][2],&le[i][3]);
		for(int i=1;i<=3;i++)
		    tmp[i]=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
