#include<bits/stdc++.h>

using namespace std;
const int N=1e4+15,M=1500005;
int read(){
	int sum=0,fg=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') fg=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*fg;
}

struct edge{
	int x,y,z,id;
	bool operator<(const edge &o) const{
		return z<o.z;
	}
} e[M];

int n,m,k,tot,c[15],fa[N];
bool valid[N*10];

int get(int x){
	if(fa[x]==x) return x;
	else return fa[x]=get(fa[x]);
}

long long solve(int st){
	memset(valid,false,sizeof(valid));
	long long res=0;
	for(int i=0;i<k;++i){
		if(st>>i&1^1) continue;
		res+=c[i+1];
		for(int j=1;j<=n;++j) valid[i*n+j]=true;
	}
	for(int i=1;i<=n+k;++i) fa[i]=i;
	for(int i=1;i<=tot;++i){
		if(e[i].id>m&&!valid[e[i].id-m]) continue;
		int x=get(e[i].x),y=get(e[i].y);
		if(x!=y) fa[x]=y,res+=e[i].z;
	}
	return res;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i)
		e[i].x=read(),e[i].y=read(),e[i].z=read(),e[i].id=i;
	tot=m;
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j)
			e[++tot].x=i+n,e[tot].y=j,e[tot].z=read(),e[tot].id=tot;
	}
	sort(e+1,e+tot+1);
	int st=(k==5)? 0: (1<<k)-1;
	long long res=1e18;
	while(st<(1<<k)) res=min(res,solve(st++));
	printf("%lld\n",res);
	return 0;
}

