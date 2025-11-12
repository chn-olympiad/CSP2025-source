#include<bits/stdc++.h>
using namespace std;
void read(int &x){//focus on types
	x=0;
	int c;
	bool flag=0;
	c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			flag=1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(flag) x=-x;
	return ;
}
void read(long long &x){//focus on types
	x=0;
	int c;
	bool flag=0;
	c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			flag=1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(flag) x=-x;
	return ;
}
void write(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
void write(long long x){
	if(x<0) x=-x,putchar('-');
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
#define N 11000
#define M 1001000
#define ll long long
//#define int long long
//2^k*mlogm(SOSdp+cruskal)(1.9e10)
int fa[N],siz[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	if(find(x)==find(y)) return false;
	if(siz[find(x)]<siz[find(y)]) swap(x,y);
	siz[find(x)]+=siz[find(y)];
	fa[find(y)]=find(x);
	return true;
}
struct Edge{
	int u,v,w;
	bool operator <(const Edge &a)const{
		return w>a.w;
	}
}edge[M];
int vill[11][N],c[14];
priority_queue<Edge> q;
ll kruskal(int vl,int n,int m,int k){
//	cout<<vl<<'\n';
	while(!q.empty()) q.pop();
	ll res=0;
	int adc=0,cct=0;
	for(int i=0;i<k;++i){
		if((vl>>i)&1){
			res+=c[i];
			++adc;
			for(int j=1;j<=n;++j){
				q.push(Edge{n+adc,j,vill[i][j]});
			}
		}
	}
	for(int i=1;i<=m;++i){
		q.push(edge[i]);
	}
	n+=adc;
	for(int i=1;i<=n;++i){
		fa[i]=i;
		siz[i]=1;
	}
	while(cct<n&&!q.empty()){
		Edge now=q.top();
		q.pop();
		if(merge(now.u,now.v)){
//			printf("%d %d merge successfully\n",now.u,now.v);
			res+=now.w;
			cct++;
		}
//		else{
//			printf("%d %d merge failed\n",now.u,now.v);
//		}
	}
	return res;
}
int n,m,k;
bool spj=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(int i=1;i<=m;++i){
		read(edge[i].u);
		read(edge[i].v);
		read(edge[i].w);
	}
	for(int i=0;i<k;++i){
		read(c[i]);
		if(c[i]!=0) spj=0;
		for(int j=1;j<=n;++j){
			read(vill[i][j]);
		}
	}
	ll ans=LLONG_MAX;
	if(spj){
		write(kruskal((1<<k)-1,n,m,k));
		return 0;
	}
	for(int i=0;i<(1<<k);++i){
		ans=min(ans,kruskal(i,n,m,k));
	}
	write(ans);
	return 0;
}
