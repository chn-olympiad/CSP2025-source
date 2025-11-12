#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int tu[10010][10010],chengxiang[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			tu[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		tu[u][v]=min(tu[u][v],w);
		tu[v][u]=min(tu[v][u],w);
	}
	for(int i=1;i<=k;i++){
		int w;
		scanf("%d",&w);
		for(int j=1,l;j<=n;j++){
			scanf("%d",&chengxiang[i][j]);
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				tu[j][k]=min(chengxiang[i][j]+chengxiang[i][k],tu[j][k]);
				tu[k][j]=min(chengxiang[i][j]+chengxiang[i][k],tu[k][j]);
			}
		}
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(tu[i][len]!=INT_MAX&&tu[len][j]!=INT_MAX){
					tu[i][j]=min(tu[i][len]+tu[len][j],tu[i][j]);
				}
			}
		}
	}
	printf("%d",tu[1][n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
