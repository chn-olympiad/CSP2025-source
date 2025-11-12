#include<bits/stdc++.h>
using namespace std;
const int maxm=2e7+5;
const int maxn=1e5+5;
long long head[maxm],a[maxn],cnt,n,m,k,vis[maxn],b[maxn],fa[maxn],mx=INT_MAX;
long long ans;
struct node{
	int next,to,w,come;
	bool operator <(const node a) const{
		return w<a.w;
	}
}edge[maxm];
inline int GetFa(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=GetFa(fa[x]);
}
inline void add(int x,int y,int w){
	edge[++cnt].next=head[x];
	edge[cnt].to=y;
	edge[cnt].w=w;
	edge[cnt].come=x;
	head[x]=cnt;
}
inline void MST(){
	for(int i=1;i<=cnt;i++){
		int x=GetFa(edge[i].come);int y=GetFa(edge[i].to);
//		printf("%d %d %d %d %d\n",edge[i].come,edge[i].to,x,y,edge[i].w);
		if(x!=y){
			fa[x]=y;
			ans+=edge[i].w;
//			printf("%d\n",ans);
		}
		else continue;
	}
}
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f*=-1;ch=getchar();
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
 	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);add(y,x,w);
	
	}
	for(int j=1;j<=k;j++) {
		int a;
		cin>>a;
	for(int i=1;i<=n;i++) cin>>b[i];
	 for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) {add(i,j,b[i]+b[j]+a);add(j,i,b[j]+b[i]+a);}
}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(edge+1,edge+1+cnt);
	MST();
//	for(int i=1;i<=n;i++) printf("%d\n",fa[i]);
	printf("%lld\n",ans);
	return 0;
}
/*
4 4 2
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4 100pts!!!!
*/
