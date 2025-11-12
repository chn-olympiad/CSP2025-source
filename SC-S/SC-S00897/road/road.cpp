#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+10;
const int maxm=2e6+10;

int read() {
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	} while(isdigit(c)) {
		x=(x<<1)+(x<<3)+(c-'0');
		c=getchar();
	} return x*f;
}

struct node{
	int u,v,val;
}edge[maxm];

int n,m,k;
int fa[maxn],c[maxn],a[12][maxn];
bool flag=1;
bool cmp(node n1,node n2) {
	return n1.val<n2.val;
}

int find(int x) {
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

int krus() {
	int cnt=0,res=0;
	for(int i=1;i<=m;i++) {
		int u=edge[i].u,v=edge[i].v,val=edge[i].val;
		int fu=find(u),fv=find(v);
		if(fu!=fv) {
//			cout<<u<<" "<<v<<"\n";
			fa[fu]=fv,cnt++,res+=val;
		}
		if(cnt==n-1) break;
	} return res;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) {
		edge[i].u=read(),edge[i].v=read(),edge[i].val=read();
	} 
	for(int i=1;i<=k;i++) {
		c[i]=read();
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++) {
			a[i][j]=read();
		}
	}
	if(flag) {
		int rt=0;
		for(int i=1;i<=k;i++) {
			for(int j=1;j<=n;j++) if(a[i][j]==0) rt=j;
			for(int j=1;j<=n;j++) {
				if(rt!=j) {
					edge[++m]=(node){rt,j,a[i][j]};
				}
			}
		}
	}
	if(k==0 || flag) {
//		cout<<flag<<"\n";
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(edge+1,edge+1+m,cmp);
		cout<<krus()<<"\n";
	}
	return 0;
}
/*
7 8 0
1 2 1
2 4 3
1 3 2
3 4 1
4 5 2
5 6 1
4 6 4
3 7 2
*/