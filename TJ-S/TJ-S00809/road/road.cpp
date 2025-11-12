#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
struct node{
	int u,v,w;
}ans[maxn];
struct edge{
	int mon;
	int r[maxn];
}us[20];

struct check{
	int sum;
	int vis;
};

check z[10010][10010];
int main(){
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++){
		cin >> ans[i].u >> ans[i].v >> ans[i].w;
	} 
	for (int i=1;i<=k;i++){
		cin >> us[i].mon;
		for (int j=1;j<=n;j++){
			cin >> us[i].r[j];
		}
	}
	int ji=0;
	
	if (k==0){
		for (int i=1;i<=m;i++){
			int x=min(ans[i].u,ans[i].v),y=max(ans[i].u,ans[i].v);
			if (z[x][y].vis!=0&&z[x][y].sum>ans[i].w){
				ji-=z[x][y].sum;
				ji+=ans[i].w;
			}else if (z[x][y].vis==0){
				ji+=ans[i].w;
				z[x][y].vis=1;
			}
		}
	}
	
	cout << ji;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
