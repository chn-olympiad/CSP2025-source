#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e4+5,M=2e6+5;
//图是联通的 
int n,m,k,p[N+100];
int tot=0,ans=0;
struct node{
	int u,v,w,nxt;
}e[M];
void add(int u,int v,int w){
	e[++tot].v=v;
	e[tot].u=u;
	e[tot].w=w;
}
bool cmp(node &x,node &y){
	return x.w<y.w;
}
int find(int x){
	if(x==p[x]){return x;}
	else{
		return p[x]=find(p[x]);
	}
}
bool mrg(int x,int y){
	int rtx=find(x);
	int rty=find(y);
	if(rtx==rty){
		return true;
	}else{
		p[x]=rty;
		return false;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=n+1,c;i<=k+n;i++){
		cin>>c;add(i,0,c);
		for(int j=1,a;j<=n;j++){
			cin>>a;
			add(0,j,a);
		}
	}
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=n+k;i++){
		p[i]=i;
	}
	for(int i=1;i<=tot;i++){
		int x=e[i].u;
		int y=e[i].v;
		if(!mrg(x,y)){
			ans+=e[i].w;
		}
	}
	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
