//The simple is wrong?
//5pts?
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stdio.h>
#define ll long long
using namespace std;
int ORY;
ll n,m,k;
struct edge{
	ll u,v,w;
}Edge[2000050],bak[2000050];
ll cnt=0;
int c[20];
int a[20][2000050];
bool vis[2000050];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fa[2000050];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
void init2(){
	for(int i=0;i<m;i++){
		Edge[i]=bak[i];
	}
}
ll ans;
void K(){
	sort(Edge,Edge+cnt,cmp);
	for(int i=0;i<cnt;i++){
		if(find(Edge[i].u)!=find(Edge[i].v)){
			fa[find(Edge[i].u)]=fa[find(Edge[i].v)];
			ans+=Edge[i].w;
		}
	}
}
int MEM;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=0;i<m;i++){
		cin>>Edge[i].u>>Edge[i].v>>Edge[i].w;
		bak[i]=Edge[i];
		cnt++;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		K();
		cout<<ans;
	}
	else if(k<=5){
		ll res=1e9;
		for(int i=0;i<pow(2,k);i++){
			ans=0;
			cnt=m;
			init2();
			for(int j=0;j<k;j++){
				if((i>>j)%2==0){
					ans+=c[j+1];
					for(int t=1;t<=n;t++){
						Edge[cnt].u=j+1;
						Edge[cnt].v=t;
						Edge[cnt].w=a[j+1][t];
						cnt++;
					}
				}
			}
			init();
			K();
			res=min(res,ans);
		}
		cout<<res;
	}
	//cout<<endl<<(&MEM-&ORY)/1024/1024<<"MB";
	return 0;
}

