//niuziru SN-S00452 xiangaoxindiyizhongxue
#include<bits/stdc++.h>
using namespace std;
#define il inline
typedef long long ll;
il int rd(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=1e5+13;
ll len,ans,tmp,n,k,m;
bool vis[N];
ll c[1000];
struct sym{
	int fr,to,w;
	il bool operator<(const sym &a)const{
		return w>a.w;
	}
};
vector<pair<int,int> > e[N],h[N];
priority_queue<sym> g;
struct nw{
	int to,w;
	il bool operator<(const nw &a)const{
		return w>a.w;
	}
};
priority_queue<nw> p;
il void Pre(){
	ans=0,vis[1]=1;
	for(auto i:e[1]) g.push({1,i.second,i.first});
	sym tp;
	while(!g.empty()){
		tp=g.top(),g.pop();
		if(vis[tp.to]) continue;
		ans+=tp.w,vis[tp.to]=1;
		h[tp.fr].push_back({tp.w,tp.to});
		h[tp.to].push_back({tp.w,tp.fr});
		for(auto i:e[tp.to]){
			if(!vis[i.second]){
				g.push({tp.to,i.second,i.first});
			}
		}
	}
}
il void prim(int st){
	nw tp;
	tmp=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=0;i<k;i++){
		if(!(st&(1<<i))) vis[i+n+1]=1;
		else vis[i+n+1]=0,tmp+=c[i+1];
	}
	while(!p.empty()) p.pop();
	p.push({1,0});
	while(!p.empty()){
		tp=p.top(),p.pop();
		if(vis[tp.to]) continue;
		tmp+=tp.w,vis[tp.to]=1;
		if(tmp>ans) break;
		for(auto i:h[tp.to]){
			if(!vis[i.second]) p.push({i.second,i.first});
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	int u,v,w;
	for(int i=1;i<=m;i++){
		u=rd(),v=rd(),w=rd();
		e[u].push_back({w,v});
		e[v].push_back({w,u});
	}
	Pre();	
	len=(1<<k)-1;
	for(int i=n+1;i<=n+k;i++){
		c[i-n]=rd();
		for(int j=1;j<=n;j++){
			w=rd();
			h[j].push_back({w,i});
			h[i].push_back({w,j});
		}
	}
	for(int i=1;i<=len;i++){
		prim(i);
		ans=min(ans,tmp);
	}
	printf("%lld",ans);
	return 0;
}
