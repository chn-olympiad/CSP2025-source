#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
const int N=2e4+5;
const int M=2e6+5;
const int inf=1e18;
inline int rd(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,k;
int tot,tot1;
struct edge{
	int u,v,w;
	bool operator<(const edge&a)const{
		return w<a.w;
	}
}e[M<<1],e1[M<<1];
void add(int u,int v,int w){
	e[++tot]=(edge){u,v,w};
}
void add1(int u,int v,int w){
	e1[++tot1]=(edge){u,v,w};
}
int f[N];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
struct node{
	int v,w;
};
vector<node>vec[15];
int c[15],ans=inf;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(re int i=1;i<=m;i++){
		int u=rd(),v=rd(),w=rd();
		add(u,v,w);
	}
	for(re int i=1;i<=k;i++){
		c[i]=rd();
		for(re int j=1;j<=n;j++){
			int v=j,w=rd();
			vec[i].push_back((node){v,w});
		}
	}
//	cerr<<"!!!\n";
//printf("!!!\n");
	for(re int i=0;i<(1<<k);i++){
		int anss=0,cnt=0;
		tot1=0;
		for(re int j=1;j<=m;j++){
			int u=e[j].u,v=e[j].v,w=e[j].w;
			add1(u,v,w);
		}
		for(re int x=1;x<=k;x++){
			if((1<<(x-1)&i)){
				//printf("i:%d x:%d\n",i,x);
				anss+=c[x];cnt++; 
				if(anss>=ans)break;
				for(re int j=0;j<vec[x].size();j++){
					int v=vec[x][j].v,w=vec[x][j].w;
					add1(x+n,v,w);
				}
			}
		}
		if(anss>=ans)continue;
		sort(e1+1,e1+tot1+1);
		int tmp=0;
		for(re int j=1;j<=n+k;j++)f[j]=j;
		for(re int j=1;j<=tot1;j++){
			int u=e1[j].u,v=e1[j].v,w=e1[j].w;
			int aa=u,bb=v;
			u=find(u),v=find(v);
			if(u==v)continue;
			///printf("%d->%d:%lld\n",u,v,w);
			f[u]=v;
			tmp++;
			anss+=w;
			if(anss>=ans)break;
			if(tmp==n+cnt-1)break; 
		}
		if(anss>=ans)continue;
		//printf("k:%d ans:%lld\n",cnt,anss);
		ans=min(ans,anss);
	}
	printf("%lld\n",ans);
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



