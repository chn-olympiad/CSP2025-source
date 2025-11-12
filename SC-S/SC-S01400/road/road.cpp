#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*f;
}
const int N=1e4+5;
int n,m,k;
struct node{
	int x,y,z;
};
vector<node> V; 
int c[15],a[15][N];
int fa[N],vis[N];
int find(int x){
	if(fa[x]==x) return x;
	return find(fa[x]);
}
bool cmp(node A,node B){
	return A.z<B.z;
}
int kl(){
	int res=0;
	for(int i=0;i<V.size();i++){
		int x=V[i].x,y=V[i].y,z=V[i].z;
		int fx=find(x),fy=find(y);
		if(fx==fy) continue;
		int uk=2e9,id;
		for(int j=1;j<=k;j++)
			for(int s=1;s<=n;s++)
				if(find(s)==fy)
					for(int s2=1;s2<=n;s2++)
						if(find(s2)==fx)
							if(uk>a[j][s2]+a[j][s]+(vis[j]?0:c[j])) uk=a[j][s]+a[j][s2]+(vis[j]?0:c[j]),id=j;
		if(z>uk){
			vis[id]=1;
			z=uk;
		}
		fa[y]=fx;
		res+=z;
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		V.push_back({min(u,v),max(u,v),w});
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(V.begin(),V.end(),cmp);
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	cout<<kl();
	return 0;
}
