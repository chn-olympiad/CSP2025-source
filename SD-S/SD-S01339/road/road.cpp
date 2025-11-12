#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int town[13][10005];
int town_num[13];
int town_cost[13];
int first_price=0;
int con[10005][10005];
bool flag[10005][10005];
int flag_city=0;
int flag_town=0;
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		town_num[i]=n;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		con[u][v]=w;
		con[v][u]=w;
		first_price+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>town_cost[i];
		first_price+=town_cost[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&town[i][j]);
			first_price+=town[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		flag_city=0;
		flag_town=0;
		int minn=99999999;
		int sum=0;
		for(int j=1;j<=n;j++){
			if(flag[i][j]!=true){
				sum+=con[i][j];
				if(con[i][j]<minn){
					minn=con[i][j];
					flag_city=j;
				}
			}
		}
		for(int j=1;j<=k;j++){
			sum+=town[k][i];
			if(town[k][i]<minn){
				minn=town[k][i];
				flag_city=0;
				flag_town=j;
			}
		}
		for(int j=1;j<=k;j++){
			if(j!=flag_town){
				town_num[j]--;
			}
		}
		
	}
	return 0;
}

