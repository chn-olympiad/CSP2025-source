#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
struct node{
	int u,v,w;
}a[2000010];
struct Node{
	int c, w[1010];
}p[100];
int n,m,k,fa[100010],flag=1,ans,e[1010][1010],tmp[1010][1010],dg[1010];
int cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
priority_queue<pair<int,pair<int,int> > > q;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) fa[i]=i;	
	for(int i=1,u,v,w;i<=m;i++){
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	for(int i=1;i<=k;i++){
		p[i].c=read();
		if(p[i].c) flag=0;
		for(int j=1;j<=n;j++) p[i].w[j]=read();
	}
	if(k==0){
		sort(a+1,a+m,cmp);
		for(int i=1;i<=m;i++){
			int xx=find(fa[a[i].u]),yy=find(fa[a[i].v]);
			if(xx!=yy){
				fa[xx]=yy;
				ans+=a[i].w;
			}
		}
		write(ans);
		putchar('\n');
	}
	if(flag){
		int cnt=1;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				a[cnt+m].u=i,a[cnt+m].v=j,a[cnt+m].w=p[i].w[j];
				++cnt;
			}
		}
		m+=cnt;
		sort(a+1,a+m,cmp);
		for(int i=1;i<=m;i++){
			int xx=find(fa[a[i].u]),yy=find(fa[a[i].v]);
			if(xx!=yy){
				fa[xx]=yy;
				ans+=a[i].w;
			}
			//cout<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<<' '<<ans<<'\n';
		}
	}
	write(ans);
	putchar('\n');
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
else if(p[i].w[j].first<=s){
				cnt = cnt-s+p[i].w[j].first;
				res++;
				if(tmp[xx][yy] != -1){
					dg[tmp[xx][yy]]--;
					if(!dg[tmp[xx][yy]]) cnt-=p[tmp[xx][yy]].c;
				}
				tmp[xx][yy]=tmp[yy][xx]=i;
				q.pop();
				q.push({p[i].w[j].first,{i,p[i].w[j].second}});
			}
			cout<<i<<' '<<cnt<<'\n';
*/

