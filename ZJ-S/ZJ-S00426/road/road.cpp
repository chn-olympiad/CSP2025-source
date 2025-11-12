#include<bits/stdc++.h>
#define N 1005
using namespace std;
int n,m,k,res,a[N],f[N][N],len,fa[N],x;
bool vis[N];
struct Node{
	int x,y,z;
}edg[N*N];
bool cmp(Node a,Node b){
	return a.z<b.z;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void kruscal(){
	for(int i=1;i<=len;i++){
		int fx=find(edg[i].x),fy=find(edg[i].y);
		if(fx!=fy){
			fa[fx]=fy;
			res+=edg[i].z;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k){
		memset(f,0x3f,sizeof f);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			f[x][y]=f[y][x]=min(f[x][y],z);
		}
		for(int i=1;i<=k;i++){
			cin>>x;
			for(int j=1;j<=n;j++)cin>>a[j];
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(j!=k)f[j][k]=f[k][j]=min(f[j][k],a[j]+a[k]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][j])edg[++len]={i,j,f[i][j]};
			}
		}
		stable_sort(edg+1,edg+1+len,cmp);
		kruscal();
		cout<<res;
	}
	else{
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			edg[++len]={x,y,z};
		}
		stable_sort(edg+1,edg+1+len,cmp);
		kruscal();
		cout<<res;
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
*/