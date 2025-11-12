#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e4+7;
//vector<int> edge[N];
//vector<int> w[N];
int c[20];
struct node {
	int u,v,w;
} ew[1000007];
int f[1000007];
bool cmp(node a,node b) {
	return a.w<b.w;
}
int findf(int a) {
	if(f[a]!=a) {
		f[a]=findf(f[a]);
	}
	return f[a];
}
void hb(int x,int y) {
	int fx=findf(x);
	int fy=findf(y);
	if(fx!=fy)f[fx]=fy;
	return;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
		for(int i=1; i<=m; i++) {
			f[i]=i;
			int u,v,w1;
			scanf("%d %d %d",&u,&v,&w1);
//			edge[u].push_back(v);
//			edge[v].push_back(u);
//			w[u].push_back(w1);
//			w[v].push_back(w1);
			ew[i].u=u;
			ew[i].v=v;
			ew[i].w=w1;
		}
		sort(ew+1,ew+m+1,cmp);
		long long ans=0;
		int esum=0;
		int i=1;
		while(esum!=n-1) {
			int fu=findf(ew[i].u);
			int fv=findf(ew[i].v);
			if(fu!=fv) {
				hb(fu,fv);
				esum++;
				ans+=ew[i].w;
			}
			i++;
		}
		cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
