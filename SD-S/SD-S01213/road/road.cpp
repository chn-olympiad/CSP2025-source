#include<bits/stdc++.h>
#define fir first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template <typename ty>
inline void read(ty &x) {
	x=0; bool f=0; char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
}
template <typename ty,typename ...T>
inline void read(ty &x,T &...te) {
	read(x); read(te...);
}
const int N=1e4+50,M=1e6+50;
struct Edge{
	int x,y,w,o;
}edge[M];
int fat[N];
int find(int x) {
	if(fat[x]==x) return x;
	return fat[x]=find(fat[x]);
}
void U(int x,int y) {
	int fx=find(x),fy=find(y);
	if(fx==fy) return ;
	fat[fx]=fy;
}
int c[12];
int a[12][N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	read(n,m,k);
	for(int i=1;i<=m;i++) 
		read(edge[i].x,edge[i].y,edge[i].w);
	
	ll res=0;
	sort(edge+1,edge+m+1,[&](const Edge x,const Edge y) {
		return x.w<y.w;
	});
	int tot=0;
	for(int i=1;i<=n;i++) fat[i]=i;
	for(int i=1;i<=m;i++) {
		if(find(edge[i].x)!=find(edge[i].y)) {
			U(edge[i].x,edge[i].y);
			res+=edge[i].w;
			edge[++tot]=edge[i];
		}
	}
	
	for(int i=1;i<=k;i++) {
		read(c[i]);
		for(int j=1;j<=n;j++) {
			read(a[i][j]);
			edge[++tot]={n+i,j,a[i][j],i};
		}
	}
	sort(edge+1,edge+tot+1,[&](const Edge x,const Edge y) {
		return x.w<y.w;
	});
	
	for(int S=0;S<1<<k;S++) {
		for(int i=1;i<=n+k;i++) fat[i]=i;
		ll sum=0;
		for(int i=1;i<=k;i++) if(S>>i-1&1) sum+=c[i];
		int pcnt=__builtin_popcount(S),cnt0=0;
		for(int i=1;i<=tot;i++) {
			if((!edge[i].o||(S>>edge[i].o-1&1))&&find(edge[i].x)!=find(edge[i].y)) {
				sum+=edge[i].w;
				U(edge[i].x,edge[i].y);
				cnt0++;
				if(cnt0==n+pcnt) break;
			}
		}
		res=min(res,sum);
	}
	
	printf("%lld",res);
	return 0;
}
