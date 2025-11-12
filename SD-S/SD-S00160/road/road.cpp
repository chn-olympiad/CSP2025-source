#include<bits/stdc++.h>
#define ri register int
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+(ch^48),ch=getchar();
	return x;
}const int M=1.2e6,N=1e4+3;
struct edge{
	int u,v,w;
	bool operator<(const edge&b)const{
		return w<b.w;
	}
}e[M];
int f[N],a[N],cnt;
int Find(int x){
	return x==f[x]?x:(f[x]=Find(f[x]));
}long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	iota(f,f+n+1,0);
	for(ri i=0;i<m;i++){
		e[i].u=read();e[i].v=read();e[i].w=read();
	}for(ri i=0,c,p;i<k;i++){
		c=read();
		for(ri j=1;j<=n;j++){
			a[j]=read();
			if(a[j]==0)p=j;
		}
		for(ri j=1;j<=n;j++){
			if(j==p)continue;
			e[m].u=j;e[m].v=p;e[m++].w=a[j];
		}
	}sort(e,e+m);
	for(ri i=0;i<m;i++){
		int x=Find(e[i].u),y=Find(e[i].v);
		if(x==y)continue;
		ans+=1ll*e[i].w;f[x]=y;cnt++;
		if(cnt==n-1)break;
	}cout<<ans;
	return 0;
}
