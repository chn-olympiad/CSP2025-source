#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;

int n,m,k;
int fa[N];
long long ans1,ans2;
long long c[15],a[15][N];
long long minn[N];//记录城市化间的最小值
long long cha;//记录城市化间的差值和，判断是否要城市化
long long maxx;//对应特殊性质

struct node {
	int u,v,w;
} e[N];

int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

bool cmp(node a,node b) {
	return a.w<b.w;
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1; i<=n+m; i++)fa[i]=i;
	//--------------最小生成树-------------------
	sort(e+1,e+m+1,cmp);
	for(int i=1; i<=m; i++) {
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy)continue;
		ans1+=e[i].w;
		fa[fx]=fy;
	}
	//------------求不城市化的ans1---------------

	for(int i=1; i<=k; i++) {
		cin>>c[i];
		cha=0;
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
			maxx=max(maxx,a[i][j]);
			if(i==1)minn[j]=a[i][j];
			else cha+=minn[j]-a[i][j];
		}
		if(maxx==0) {
			if(c[i]==0)cout<<0;
			else cout<<min(ans1,c[i]);
			return 0;
		}
		if(cha>c[i]||i==1) {
			for(int j=1; j<=n; j++) {
				minn[j]=min(minn[j],a[i][j]);
			}
			ans2+=c[i];
//			q.push(i);//记录要城市化的节点
		}
	}
//	for(int i=1; i<=n; i++)cout<<minn[i]<<" ";
	for(int i=m+1; i<=m+n; i++) {
		e[i].u=n+1,e[i].v=i-m,e[i].w=minn[i-m];
	}
	m+=n;
	for(int i=1; i<=m; i++)fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1; i<=m; i++) {
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy)continue;
		ans2+=e[i].w;
		fa[fx]=fy;
	}
	cout<<min(ans1,ans2);
	return 0;
}
//神兽保佑，代码无 bug!!!
/*
5 8 2
1 4 6
2 3 7
4 2 5
4 3 4
5 1 1
5 2 8
5 3 2
5 4 4
*/
