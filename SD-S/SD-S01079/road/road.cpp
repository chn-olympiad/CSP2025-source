#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
const int M=2e6+10;
inline long long read(){
	long long f=1,x=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return f*x;
}
int n,m,k;
struct node{
	int u,v,w;
}d[M];
bool operator <(const node &a,const node &b){
	if(abs(a.w)==abs(b.w)) return a.u<b.u;
	return abs(a.w)<abs(b.w);
}
int c[20],acp[20];
int fa[N];
int fd(int a){
	int x=a;
	while(fa[x]!=x) x=fa[x];
	fa[a]=x;
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n+k+5;i++) fa[i]=i;
	for(int i=0;i<m;i++){
		d[i].u=read(),d[i].v=read(),d[i].w=read();
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			d[cnt].u=i+n,d[cnt].v=j,d[cnt++].w=-(c[i]+read());
		}
	}
	sort(d,d+cnt);
//	for(int i=0;i<cnt;i++){cout<<d[i].u<<' '<<d[i].v<<' '<<d[i].w<<'\n';}
	int sum_node=0;
	long long ans=0;
	for(int i=0;i<cnt;i++){
		if(fd(d[i].u)==fd(d[i].v)) continue;
		fa[d[i].u]=fa[d[i].v];
		if(d[i].w<0){
			if(!acp[d[i].u-n]) --sum_node;
			d[i].w=-d[i].w;
			++acp[d[i].u-n];
		}
		++sum_node;
		ans+=d[i].w;
		if(sum_node==n-1) break;
	}
	for(int i=1;i<=k;i++){
		ans-=acp[i]*c[i];
		if(acp[i]) ans+=c[i];
//		cout<<acp[i]<<' '<<i<<'\n';
	}
	cout<<ans;
	return 0;
}
