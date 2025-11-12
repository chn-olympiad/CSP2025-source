#include<iostream>
#include<algorithm>
using namespace std;
inline char gc(){
	static char BB[1<<20],*S=BB,*T=BB;
	return S==T&&(T=(S=BB)+fread(BB,1,1<<20,stdin),S==T)?EOF:*S++;
}
inline int read(){
	int x=0;char ch=gc();
	while(ch<48) ch=gc();
	while(ch>=48) x=(x<<3)+(x<<1)+(ch^48),ch=gc();
	return x;
}
const int N=1e4+10,M=1.1e6+10,K=15;
int n,m,k;
struct node{int x,y,z;}a[M],b[M];
int c[K],d[K][N];
int c1[K],cnt;
int f[N];
int Find(int x){
	if(f[x]==x) return x;
	return f[x]=Find(f[x]);
}
bool cmp(node x,node y){return x.z<y.z;}
long long sum,ans=1e18;int tot,num;
void kruskal(){
	for(int i=1;i<=n+cnt;i++) f[i]=i;num=0;
	sort(b+1,b+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		int xx=Find(b[i].x),yy=Find(b[i].y);
		if(xx==yy) continue;
		f[xx]=yy;
		sum+=b[i].z;
		if(++num==n+cnt||sum>ans) break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].z=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) d[i][j]=read();
	}
	for(int p=0;p<=(1<<k);p++){
		for(int i=1;i<=m;i++) b[i]=a[i];
		sum=cnt=0;
		for(int i=1;i<=k;i++) if((p>>(i-1))&1) c1[++cnt]=i,sum+=c[i];
		if(sum>ans) continue;
		tot=m;
		for(int i=1;i<=cnt;i++) for(int j=1;j<=n;j++){
			tot++;b[tot].x=n+i;b[tot].y=j;b[tot].z=d[c1[i]][j];
		}
		kruskal();
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}

