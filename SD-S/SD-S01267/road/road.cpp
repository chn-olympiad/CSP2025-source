#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
const int N=2e6+7;
int n,m,k,head[N],u,v,w,idx,ans,cnt,fa[10005];
struct node{
	int u,v,w;
}e[N];
void add(int a,int b,int c){
	e[++idx]={a,b,c};
	return;
}
int find(int x){
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void kruskal(){
	sort(e+1,e+idx+1,cmp);
	for(int i=1;i<=idx;i++){
		int ex=find(e[i].u),ey=find(e[i].v);
		if(ex==ey) continue;
		ans+=e[i].w;
		cout<<e[i].w<<" ";
		cnt++;
		fa[ex]=ey;
		if(cnt==n-1) break;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int Imin=0x3f3f3f3f,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=10000;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		sum+=w;
		add(u,v,w);
	}
	if(k==0){
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=k;i++){
		int x,y,pos=0,num=0;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>y;
			add(i,j,y+x);
			if(y!=0){
				pos=1;
			}
			num+=y;
		}
		if(pos==0 && x==0){
			cout<<0;
			return 0;
		} 
		else if(pos==0 && x!=0){
			cout<<x;
			return 0;
		}
		else if(pos!=0 && x==0){
			Imin=min(Imin,num);
		}
		else if(pos!=0 && x==0 && i==k){
			cout<<Imin;
			return 0;
		}
	}
	kruskal();
	cout<<ans;
	return 0;
} 
