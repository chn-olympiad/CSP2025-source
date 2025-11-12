#include<bits/stdc++.h>
using namespace std;
struct Pos{
	int u;
	int v;
	int w;
}r[1000010];
int price[1050][1050],price1[15][10050];
int c[110],lj[1010][1010];
int n,m,k;
long long ans=0,cnt=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		r[i].u=u,r[i].v=v,r[i].w=w;
		price[u][v]=w;
		cnt+=w;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			int p;
			cin>>p;
			price1[j][i]=p;
		}
	}
	if(k==0){
		cout<<cnt;
		return 0;
	}
	else{		
		memset(lj,0x3f,sizeof(lj));
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					lj[j][k]=min(lj[j][k],price1[i][j]+price1[i][k]);
				}
			}
		}
		
		for(int i=1;i<=m;i++){
			int px=r[i].u,py=r[i].v;
			if(price[px][py]<=lj[px][py])ans+=price[px][py];
			else ans+=lj[px][py];
		}
		cout<<ans;
	}	
	return 0;
}
