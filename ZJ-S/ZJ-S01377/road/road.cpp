#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[11],sum[2];
vector<int> v[11];
struct Road{
	int v[10005],w[10005],zhib;
	void an(Road num){
		for(int i = 0;i < num.zhib;i++){
			v[zhib] = num.v[i];
			w[zhib++] = num.w[i];
		}
	}
}road[10005];
void dfs(int x){
	bool ch[10005];
	ch[x] = 1;
	for(int j = 1;j < n;j++){
		//printf("%d %d  ",ch[2],ch[3]);
		int minn = 0;
		while(ch[road[x].v[minn]]&&minn<road[x].zhib)minn++;
		for(int i = minn+1;i < road[x].zhib;i++){
			if(road[x].w[i] < road[x].w[minn]&&!ch[road[x].v[i]]){
				//printf("%d %d %d ",minn,road[x].w[i],road[x].v[minn]);
				minn = i;
				//printf("%d    ",i);
			}
		}if(minn == road[x].zhib || ch[road[x].v[minn]]) return ;
		//printf("%d ",minn);
		road[x].an(road[road[x].v[minn]]);
		ch[road[x].v[minn]] = 1;
		sum[0]+=road[x].w[minn];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0;i < m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		road[u].v[road[u].zhib] = v;
		road[u].w[road[u].zhib++] = w;
		road[v].v[road[v].zhib] = u;
		road[v].w[road[v].zhib++] = w;
	}
	for(int i = 0;i < k;i++){
		scanf("%d",&c[i]);
		for(int i = 0;i < n;i++){
			int ls;
			scanf("%d",&ls);
			v[i].push_back(ls);
		}
	}
	dfs(1);
//	for(int i = 1;i <= n;i++){
//		for(int j = 0;j < road[i].zhib;j++){
//			printf("%d ",road[i].v[j]);
//		}
//		printf("\n");
//	}
	if(sum[0]>sum[1]&&sum[1]!=0)printf("%d",sum[1]);
	else printf("%d",sum[0]);
	return 0;
}

