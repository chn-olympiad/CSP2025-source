#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot1,tot2;
long long ans=0xffffffff;
int rds[10015][10015];
long long path[10015];
bool to[10015];
vector<int> route;

void dfs(int rt,int stp,int lft){
	cout<<"a";
	if(stp>1) cout<<stp<<" "<<path[stp-1]<<" "<<route[stp-1]<<" "<<rds[route[stp-1]][rt];
	if(stp>1) path[stp]=path[stp-1]+rds[route[stp-1]][rt];
	cout<<"e";
	if(lft==0){
		ans=min(ans,path[stp]);
		cout<<"c";
		return;
	}
	cout<<"d";
	for(int i=1;i<stp-1;i++){
		int t=rds[route[i]][rt];
		if(t>=0&&t<=path[stp]-path[route[i]]) rds[route[i]][rt]=-1;
	}
	route.push_back(rt);
	for(int i=1;i<=stp-1;i++) cout<<route[i]<<" ";
	cout<<"\n";
	to[rt]=false;
	for(int i=1;i<=n+k;i++){
		if(rds[rt][i]>=0&&to[i]){
			cout<<i;
			if(i>=1&&i<=n) dfs(i,stp+1,lft-1);
			else dfs(i,stp+1,lft);
		}
	}
	route.pop_back();
	to[rt]=true;
	cout<<"b";
}

int main(){
	freopen("road1.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	memset(rds,-1,sizeof(rds));
	for(int i=1;i<=n;i++){
		scanf("%d%d",&tot1,&tot2);
		scanf("%d",&rds[tot1][tot2]);
		rds[tot2][tot1]=rds[tot1][tot2];
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&tot1);
		for(int j=1;j<=n;j++){
			scanf("%d",&rds[n+i][j]);
			rds[n+i][j]+=tot1;
			rds[j][n+i]=rds[n+i][j];	
		}
	}
	memset(to,true,sizeof(to));
	dfs(1,1,n-1);
	cout<<ans;
	return 0;
	fclose(stdin);
}
