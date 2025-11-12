#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e5+6;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct Node{
	int x,y,w;
	bool operator < (const Node &A){
		return w<A.w;
	}
}s[N];
int c[15],a[15][N],ans,fa[M];
vector< pair<int,int> > edges[M];
bool ok=true;
inline int sfind(int x){
	if(x==fa[x])
		return x;
	return fa[x]=sfind(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		s[i].x=read(),s[i].y=read(),s[i].w=read();
	for(int i=1;i<=n;i++)
		fa[i]=i;
	if(!k){
		for(int i=1;i<=n;i++)
			fa[i]=i;
		int cnt=n;
		sort(s+1,s+m+1);
		for(int i=1;i<=m;i++){
			int x=sfind(s[i].x),y=sfind(s[i].y);
			if(x!=y){
				cnt--;
				ans+=s[i].w;
				fa[x]=y;
			}
			if(cnt==1)
				break;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			s[++m].x=i,s[m].y=j,s[m].w=a[i][j]+c[i];
	int cnt=n;
	sort(s+1,s+m+1);
	for(int i=1;i<=m;i++){
		int x=sfind(s[i].x),y=sfind(s[i].y);
		if(x!=y){
			cnt--;
			ans+=s[i].w;
			fa[x]=y;
		}
		if(cnt==1)
			break;
	}
	printf("%lld",ans);
	return 0;
}

