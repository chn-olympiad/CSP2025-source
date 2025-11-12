#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline void read(int &x){
	char c=getchar();x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))
		x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
const int N=1e6+5,M=1e4+15;
struct A{
	int x,y,z;
}a[N],b[N*11];
int n,m,k,f[N],c[15];
ll s,mn;
inline int cmp(A u,A v){return u.z<v.z;}
inline int find(int u){
	return u==f[u]?u:(f[u]=find(f[u]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for (int i=1;i<=m;i++)
		read(a[i].x),read(a[i].y),read(a[i].z);
	sort(a+1,a+m+1,cmp);
	int t=0;
	for (int i=1;i<=n;i++)f[i]=i;
	for (int i=1,u,v;i<=m;i++){
		u=find(a[i].x),v=find(a[i].y);
		if(u==v)continue;
		b[++t]=a[i];f[u]=v;mn+=a[i].z;
		if(t==n-1)break;
	}
	for (int i=1,x;i<=k;i++){
		read(c[i]);
		for (int j=1;j<=n;j++)
			read(x),b[++t]=(A){j,i+n,x};
	}
	sort(b+1,b+t+1,cmp);
	int u,v,e,g;
	for (int i=1,u,v;i<(1<<k);i++){
		s=0;e=n-1;
		for (int j=0;j<k;j++)
			if(i&(1<<j))s+=c[j+1],e++;
		for (int j=1;j<=n+k;j++)f[j]=j;
		for (int j=1;j<=t;j++){
			v=b[j].y;
			if(v>n&&(i&(1<<v-n-1))==0)continue;
			u=find(b[j].x),v=find(v);
			if(u==v)continue;
			e--;f[u]=v,s+=b[j].z;
			if(!e)break;
		}
		mn=min(s,mn);
	}
	printf("%lld\n",mn);
}
