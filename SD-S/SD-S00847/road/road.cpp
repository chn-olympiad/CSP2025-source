#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P pair<int,int>
#define rd read()
#define x first
#define y second
#define y1 Y1
#define y0 Y0
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
char buf[(1<<21)+10],obuf[(1<<21)+10],*p1=buf,*p2=buf,*O=obuf;int ol=(1<<21);
#define getchar() (((p1==p2)&&(p2=((p1=buf)+fread(buf,1,ol,stdin)),p1==p2))?EOF:*p1++)
#define flush() (fwrite(obuf,1,O-obuf,stdout),O=obuf)
#define putchar(x) (((O-obuf==ol)&&(flush(),O-obuf==ol))?:*O++=x)
inline int read(int u=0,char c=getchar(),bool f=false){
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) u=(u<<1)+(u<<3)+(c^'0');
	return f?-u:u;
}
inline void wt(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) wt(x/10);
	putchar((x%10)^'0');
}
inline void wt(ll x,char c){wt(x);putchar(c);}
const int N=2e4+10,M=1e6+10;
int n,m,k,f[N],szt,cnt,a[12][N],sz[N],c[10];ll ans,sum;
struct node{
	int u,v,w;
	bool operator<(const node v)const{return w<v.w;}
};vector<node>e0,e,et;
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return ;
	if(sz[x]<sz[y]) swap(x,y);
	sz[x]+=sz[y],f[y]=x;
}
main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd,m=rd,k=rd;
	for(int i=1;i<=m;i++){
		int u=rd,v=rd,w=rd;
		e0.push_back({u,v,w});
	}sort(e0.begin(),e0.end());
	for(int i=1;i<=n;i++) f[i]=i,sz[i]=1;
	for(node v:e0){
		if(find(v.u)==find(v.v)) continue;
		merge(v.u,v.v);e.push_back(v);cnt++;ans+=v.w;
		if(cnt==n-1) break;
	}
	for(int i=1;i<=k;i++){c[i]=rd;
		for(int j=1;j<=n;j++){
			a[i][j]=rd;
		}
	}for(int s=1;s<(1<<k);s++){
		szt=cnt=sum=0;et.clear();
		for(node v:e) et.push_back(v);
		for(int j=1;j<=k;j++) if(s>>j-1&1){
			sum+=c[j];szt++;
			for(int i=1;i<=n;i++) et.push_back({n+j,i,a[j][i]});}
		sort(et.begin(),et.end());
		for(int i=1;i<=n+k;i++) f[i]=i,sz[i]=1;
//		for(int j=1;j<=k;j++) if(s>>j-1&1){sum+=c[j];
//			for(int i=1;i<=n;i++) tmp[i]=min(tmp[i],a[j][i]);}
		for(node v:et){
			if(find(v.u)==find(v.v)) continue;
			merge(v.u,v.v);cnt++;sum+=v.w;
			if(cnt==n+szt-1) break;
		}ans=min(ans,sum);
//		int szk=0;for(int i=0;i<=n;i++) if(find(i)==i) szk++;
//		assert(szk==1);
	}wt(ans,'\n');
	return flush(),0;
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
