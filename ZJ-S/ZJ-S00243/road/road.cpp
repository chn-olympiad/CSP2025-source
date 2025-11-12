#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
long long ans=INT_MAX,sum=0;
struct Node {
	int u,v,w;
};
vector<Node> ve;
bool cmp(Node x,Node y) {
	return x.w<y.w;
}
int a[10005][10005];
int cun[15][10005];
int f[10055];
int need[15];
int vis[15];
int find(int x) {
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y) {
	int fx=find(x),fy=find(y);
	if(fx!=fy)f[fx]=fy;
}
int n,m,k;
long long func(vector<Node> ve,long long sum) {
	for(int i=1; i<=n; i++)f[i]=i;
	sort(ve.begin(),ve.end(),cmp);
	int cnt=0;
	for(int i=0; i<ve.size(); i++) {
		Node now=ve[i];
//		cout<<now.u<<' '<<now.v<<' '<< now.w<<'\n';
		if(find(now.u)!=find(now.v)) {
			cnt++;
			merge(now.u,now.v);
			sum+=now.w;
		}
		if(cnt>=n||sum>=ans)break;
	}
	return sum;
} //最小生成树
void dfs(int idx,vector<Node> ve,long long sum) {
	if(idx==k+1) {
//		cout<<func(ve,sum)<<'\n';
		ans=min(ans,func(ve,sum));
		return;
	}
	vector<Node> tmp=ve;
	queue<Node> q;
	int del=0;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++) {
			if(cun[idx][i]+cun[idx][j]<a[i][j]) {
				tmp.push_back({i,j,cun[idx][i]+cun[idx][j]});
				q.push({i,j,a[i][j]});
				a[j][i]=a[i][j]=cun[idx][i]+cun[idx][j];
			}
		}
	dfs(idx+1,tmp,sum+need[idx]);
	while(!q.empty()) {
		Node now=q.front();
		q.pop();
		a[now.u][now.v]=a[now.v][now.u]=now.w;
	}
	dfs(idx+1,ve,sum);
}//遍历k
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			a[i][j]=INT_MAX;
	for(int i=1; i<=m; i++) {
		int u=read(),v=read(),w=read();
		ve.push_back({u,v,w});
		a[u][v]=a[v][u]=w;
	}
	for(int i=1; i<=k; i++) {
		need[i]=read();
		for(int j=1; j<=n; j++)cun[i][j]=read();
	}
	dfs(1,ve,0);
	cout<<ans<<'\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
