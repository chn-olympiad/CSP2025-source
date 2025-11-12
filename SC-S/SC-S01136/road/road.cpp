#include<bits/stdc++.h>
using namespace std;
const int M=1e6+1e5+5,N=1e4+20;
int n,m,k,c[N];
int totm,totn,fa[N];
long long ans;
bool vst[15];
struct edge{
	int a,b,w;
	bool operator < (const edge &p)	const{
		return p.w<w;
	}
};
edge e[N];

inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+ch-(1<<4)-(1<<5);
		ch=getchar();
	}
	return s*f;
}

int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}

void kruskal(){
	for(int i=0;i<m;i++){
		int a=e[i].a,b=e[i].b;
		int ra=find(a),rb=find(b);
		if(ra==rb)	continue;
		if(b>a)	swap(a,b);
		if(a>=m&&!vst[a-m])	ans+=c[a-m],vst[a-m]=true;
		fa[ra]=rb;
		ans+=e[i].w; 
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=0;i<m;i++){
		int x,y,z;cin>>x>>y>>z; 
		e[i]={x,y,z};
	}
	totm=m;
	for(int i=0;i<k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			e[totm]={i,j,x};
			totm++;
		}
	}
	sort(e,e+totm);
	totn=n+k;
	for(int i=1;i<=totn;i++)	fa[i]=i;
	kruskal();
	cout<<ans;
	return 0;
}