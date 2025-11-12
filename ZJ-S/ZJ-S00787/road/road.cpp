#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=ch=='-'?-f:f,ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=1e4+10;
int n,m,k;
bool use[15];
long long fa[N],ans,c[N];
struct Furina{
	int u,v,w;
	bool operator<(const Furina B)const{return w>B.w;}
};
priority_queue<Furina>q,Q[15];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void init(){for(int i=1;i<=n+k;i++)fa[i]=i;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	init();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		q.push({u,v,w});
	}
	for(int i=1;i<=k;i++){
		use[i]=1;
		c[i]=read();
		int w;
		for(int j=1;j<=n;j++)w=read(),Q[i].push({i+n,j,w});
	}
	int cnt=0;
	int dot=n;
	while(!q.empty()){
		auto tmp=q.top();
		int u=tmp.u,v=tmp.v,w=tmp.w;
		int j=-1,now=w;
		for(int i=1;i<=k;i++)if(!Q[i].empty()&&Q[i].top().w+use[i]*c[i]<now)j=i,now=Q[i].top().w+use[i]*c[i],u=Q[i].top().u,v=Q[i].top().v;
		if(j==-1)q.pop();
		else Q[j].pop(),dot=use[j]==1?dot+1:dot,use[j]=0;
		int U=getfa(u),V=getfa(v);
		if(U==V)continue;
		fa[U]=V;
		ans+=now;
		cnt++;
		if(cnt==dot-1)break;
	}
	cout<<ans<<endl;
	return 0;
}
//Luogu user :I_Love_Furina
//Luogu uid 1113349
//Genshin Impact uid 275713829
//Fuirna!!!
//RP++