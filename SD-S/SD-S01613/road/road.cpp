#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char *p1,*p2,buf[1000010]; 
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
int read(){
	int x=0;
	char c=gc();
	while(c<48)c=gc();
	while(47<c)x=(x<<3)+(x<<1)+(c&15),c=gc();
	return x;
}
struct EDGE{
	int frm,to,w,id;
	unsigned char operator<(const EDGE&_)const{
		return w<_.w;
	}
}edge[1000010];
int f[11000],w[11000];
int findf(int k){
	return f[k]?f[k]=findf(f[k]):k;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),K=read(),N=1<<K,cnt=0,x,y,tot=0;
	ll ans=0,res;
	for(int i=1;i<=m;++i){
		edge[i].frm=read();
		edge[i].to=read();
		edge[i].w=read();
	}
	sort(edge+1,edge+m+1);
	for(int i=1;i<=m;++i){
		if((x=findf(edge[i].frm))!=(y=findf(edge[i].to))){
			f[x]=y;
			ans+=edge[i].w;
			edge[++tot]=edge[i];
		}
	}
	for(int i=1;i<=K;++i){
		w[i]=read();
		for(int j=1;j<=n;++j){
			edge[++tot].frm=n+i;
			edge[tot].to=j;
			edge[tot].w=read();
			edge[tot].id=i;
		}
	}
	sort(edge+1,edge+tot+1);
	for(int s=1;s<N;++s){
		res=0;
		cnt=n+__builtin_popcount(s);
		memset(f,0,sizeof f);
		for(int i=1;i<=K;++i)if(s>>i-1&1)res+=w[i];
		for(int i=1;i<=tot&&cnt!=1;++i){
			if((!edge[i].id||(s>>edge[i].id-1&1))&&(x=findf(edge[i].frm))!=(y=findf(edge[i].to))){
				--cnt;
				f[x]=y;
				res+=edge[i].w;
			}
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}
