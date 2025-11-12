#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10,M=2e6+10;
int val[15],t[N],ans[2000],vis[15];
int n,m,k;
int minn=1e14;
struct NODE{
	int u,v,w;
}a[M];
struct node{
	int f,cnt,siz;
}fa[N];
int read(){
	int s=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
}
bool cmp(NODE x,NODE y){
	return x.w<y.w;
}
int fd(int x){
	if(fa[x].f==x)return x;
	return fa[x].f=fd(fa[x].f);
}
void hb(int u,int v){
	int fat=fd(v);
	fa[fat].cnt+=fa[fa[u].f].cnt;
	fa[fat].siz+=fa[fa[u].f].siz;
	fa[u].f=fat;
	
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
//	cout<<n+k;
	for(int i=1;i<=m;i++){
		a[i].u=read(),a[i].v=read(),a[i].w=read();
		if(a[i].u<a[i].v)swap(a[i].u,a[i].v);
	}
	
	for(int i=n+1;i<=n+k;i++){
		fa[i].f=i;fa[i].siz=1;
		val[i-n]=read();
		fa[i].siz=0;
		for(int j=1;j<=n;j++){
			a[++m].u=i,a[m].v=j;
			a[m].w=read();
		}
	}
//	for(int i=1;i<=m;i++)cout<<a[i].w<<endl;
	sort(a+1,a+1+m,cmp);
	
	for(int now=0;now<(1<<k);now++){
		for(int i=1;i<=n+k;i++){
			fa[i].cnt=0;
		}
		for(int i=1;i<=n;i++){
			fa[i].siz=1;
		}
		for(int i=n+1;i<=n+k;i++){
			fa[i].siz=0;
		}
		for(int i=1;i<=n+k;i++){
			fa[i].f=i;
//			cout<<fa[i].f<<' ';
		}
		memset (vis,0,sizeof(vis));
		
//		cout<<fa[1].f;
//		for(int i=1;i<=n+k;i++)cout<<fa[i].f<<' ';
		for(int i=0;i<k;i++){
			if((1<<i)&now){
				vis[i+1]=1;
				ans[now]+=val[i+1];
			}
		}
//		cout<<now<<" "<<u<<endl;
		for(int i=1;i<=m;i++){
			int u=a[i].u,v=a[i].v,w=a[i].w;
//			cout<<w<<endl;
			if(u>n&&(!vis[u-n])){
//				cout<<u<<endl;
				continue;
			}
//			if(now==1)
//			cout<<fa[fd(v)].siz;
			if(fa[fd(u)].siz==n||fa[fd(v)].siz==n)break;
			if(fd(u)!=fd(v)) {
//				if(now==1)
//					cout<<u<<' '<<v<<endl;
				hb(u,v);
				if(now==1)
//				cout<<fd(u)<<endl;
				fa[fd(u)].cnt=fa[fd(u)].cnt+w;
//				cout<<fa[fd(u)].cnt<<endl;
			}
		}
		ans[now]+=fa[fd(1)].cnt;
		minn=min(minn,ans[now]);
	}
	cout<<minn;
	return 0;
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

