#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+10;
const int M=1e3+10;
int n,m,k;
struct ROAD{
	int u,v,w;
}e[N],cx[N];
int f[N];
bool cmp(ROAD A,ROAD B){
	return A.w<B.w;
}
int find(int x){
	if(f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}
void merge(int x,int y){
	f[x]=y; 
}
int ww[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0); 
	bool check=true;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
	} 
	sort(e+1,e+1+m,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			merge(fx,fy);
			ans+=e[i].w;
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		if(c!=0){
			check=false;
		}
		for(int j=1;j<=n;j++){
			cin>>ww[j];
			if(ww[j]!=0) check=false;
		}
	}
	if(check){
		cout<<0;
		return 0;
	}
	return 0;
}
