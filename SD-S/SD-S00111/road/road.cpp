#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,K=15,M=1e6+5;
int n,m,k;
int c[K];
int fa[N+K];
vector<int> a[N];
struct node{
	int x,y,z;
}e[M],ee[M+K*N];
bool vis[K];
int nn,mm;
long long ansz=1e18;
int find(int x){
	if(x==fa[x]) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y){
	if(find(x)==find(y)){
		return ;
	}
	x=find(x);
	y=find(y);
	fa[x]=y;
}
bool cmp(node x1,node x2){
	return x1.z<x2.z;
}
void Kruskal(){
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	long long ans=0;
	for(int i=1;i<=m;i++){
		if(find(e[i].x)!=find(e[i].y)){
			merge(e[i].x,e[i].y);
			ans+=(long long)e[i].z;
		}
	}
	printf("%lld",ans);
}
void Kruskall(long long ans){
	sort(ee+1,ee+1+mm,cmp);
	for(int i=1;i<=nn;i++){
		fa[i]=i;
	}
	for(int i=1;i<=mm;i++){
		if(find(ee[i].x)!=find(ee[i].y)){
			merge(ee[i].x,ee[i].y);
			ans+=(long long)ee[i].z;
		}
	}
	ansz=min(ansz,ans);
}
void dfs(int num){
	if(num>k){
		nn=n;
		mm=m;
		for(int i=1;i<=m;i++){
			ee[i]=e[i];
		}
		long long ans=0;
		for(int i=1;i<=k;i++){
			if(vis[i]){
				nn++;
				ans+=c[i];
				for(int j=0;j<a[i].size();j++){
					ee[++mm].x=nn;
					ee[mm].y=j+1;
					ee[mm].z=a[i][j];
				}
			}
		}
		Kruskall(ans);
		return ;
	}
	vis[num]=1;
	dfs(num+1);
	vis[num]=0;
	dfs(num+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].z;
	}
	bool flagA=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flagA=0; 
		for(int j=1;j<=n;j++){
			int z;
			cin>>z;
			a[i].push_back(z);
			if(z!=0) flagA=0;
		}
	}
	if(k>0&&flagA){
		printf("0");
		return 0;
	}
	if(k==0){
		Kruskal();
		return 0;
	}
	dfs(1);
	printf("%lld",ansz);
	return 0;
}
