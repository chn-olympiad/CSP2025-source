#include<bits/stdc++.h>
using namespace std;
const int maxm=2e7+5;
const int maxn=1e4+5;
long long head[maxm],a[maxn],cnt,n,m,k,vis[maxn],b[maxn],fa[maxn],mx=INT_MAX,q;
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
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	while(q--) printf("%d\n",n);
	return 0;
}
/*
4 4 2
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4 10pts pls!!!!
*/
