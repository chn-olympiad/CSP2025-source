#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
#define re register
using namespace std;
const int N=1e6+10;
inline int read(int &x){
	int k=0,f=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		k=(k<<3)+(k<<1)+(c^'0');
		c=getchar();
	}
	x=k*f;
}
int n,m,k,t;
int c[N]={0};
int minn=0x3f3f3f3f3f3f3f3f;
struct e{
	int x,y,z;
	int id;
}edge[N*6];
bool cmp(e a,e b){
	return a.z<b.z;
}
int fa[N]={0};
int find(int x){
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}
int kl(int pd,int point){
	int d=0,f=0;
	for(re int i=1;i<=n+k;i++) fa[i]=i;
	for(re int i=1;i<=m;i++){
		if(f==point-1) break;
		if(edge[i].id==0||(edge[i].id!=0&&(pd&(1<<edge[i].id-1)))){
			if(find(edge[i].x)!=find(edge[i].y)){
				f++;
				fa[find(edge[i].x)]=find(edge[i].y);
				d+=edge[i].z;
			}
		}
	}
	if(f!=point-1) return -1;
	return d;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(re int i=1;i<=m;i++){
		read(edge[i].x),read(edge[i].y),read(edge[i].z);
		edge[i].id=0;
	}
	for(re int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			read(t);
			edge[++m].x=j;
			edge[m].y=n+i;
			edge[m].z=t;
			edge[m].id=i;
		}
	}
	sort(edge+1,edge+1+m,cmp);
	for(re int i=0;i<=(1<<k)-1;i++){
		int sum=0,point=n;
		for(int j=1;j<=k;j++) if(i&(1<<j-1)) sum+=c[j],point++;
		int r=kl(i,point);
		if(r!=-1) minn=min(minn,sum+r);
	}
	printf("%lld\n",minn);
	return 0;
}
