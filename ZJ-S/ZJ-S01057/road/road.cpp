#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e4+15,M=1e6+5;
int n,m,k,u,v,a,f[N],s[N],p[N],sjy;
LL ans=1e18,c[N];
struct op{
	int u,v,a;
	bool operator<(const op &A)const{
		return a<A.a;
	}
}b[11][N],d[M];
inline int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool hb(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return 0;
	++sjy;
	if(s[x]>s[y])swap(x,y);
	f[x]=y,s[y]+=s[x];
	return 1;
}
LL js(int S){
	LL ct=0;
	for(int i=1;i<=n+k;i++){
		f[i]=i,s[i]=1;
	}
	sjy=1;
	for(int i=0;i<=k;i++){
		p[i]=1;
		if((S>>i)&1)ct+=c[i],--sjy;
	}
	while(sjy!=n-1){
		a=0;
		for(int i=0;i<=k;i++){
			if(((S>>i)&1)&&p[i]<=n-(i==0)){
				if(b[i][p[i]].a<b[a][p[a]].a)a=i;
			}
		}
		u=b[a][p[a]].u,v=b[a][p[a]].v;
		if(hb(u,v))ct+=b[a][p[a]].a;
		++p[a];
	}
	return ct;
}
inline int read(){
	int x=0;
	char c=getchar();
	while(c<48||c>57)c=getchar();
	while(48<=c&&c<=57)x=x*10+c-48,c=getchar();
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		d[i]={read(),read(),read()};
	}
	for(int i=1;i<=n;i++)f[i]=i,s[i]=1;
	sort(d+1,d+m+1),sjy=0,a=1;
	while(sjy!=n-1){
		u=d[a].u,v=d[a].v,++a;
		if(hb(u,v)){
			b[0][sjy]=d[a-1];
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",c+i);
		for(int j=1;j<=n;j++){
			scanf("%d",&a);
			b[i][j]={j,n+i,a};
		}
		sort(b[i]+1,b[i]+n+1);
	}
	for(int i=0;i<(1<<k);i++){
		ans=min(ans,js(1+i*2));
	}	
	cout<<ans<<"\n";
	return 0;
}
