#include<bits/stdc++.h>
using namespace std;
int head[10005],cnt=1,dst[10005],dis[10005];
bool f[10005];
priority_queue<pair<int,int> >q;
struct edge{
	int to,w,nxt;
}a[2000005];
struct node{
	int u,v,w;
}b[1000005];
bool cmp(node aa,node bb){
	return aa.w<bb.w;
}
void add(int u,int v,int w){
	a[cnt].to=v;
	a[cnt].w=w;
	a[cnt].nxt=head[u];
	head[u]=cnt;
	cnt++;
	return;
}
//void D(int s){
//	memset(f,0,sizeof(f));
//	memset(dis,0,sizeof(dis));
//	q.push(make_pair(0,s));
//	while(!q.empty()){
//		int x=q.top().second;
//		f[x]=1;
//		q.pop();
//		for(int i=head[x];i;i=a[i].nxt){
//			if(f[y])continue;
//			if(dis[y]>dis[x]+a[i].w){
//				dis[y]=dis[x]+a[i].w;
//				q.push(make_pair(-dis[y],y));
//			}
//		}
//	}
//	return;
//}
int main(){
	freopen("road2.in","r",stdin);
	freopen("road.out","w",stdout);
//	memset(dd,0x3f,sizeof(dd));
	int n,m,k,u,v,w;
	long long l=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		b[i].u=u;
		b[i].w=w;
		b[i].v=v;
//		printf("%d\n",i);
	}
	sort(b+1,b+1+m,cmp);
	for(int i=n-1;i>=1;i--){
		add(b[i].u,b[i].v,b[i].w);
		add(b[i].v,b[i].u,b[i].w);
		l+=b[i].w;
//		printf("%d\n",b[i].w);
	}
//	printf("%d %d\n",cnt,l);
	for(int t=1;t<=k;t++){
		int minn=INT_MAX,mn=INT_MAX,mi,mini;
		scanf("%d",&w);
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i].w);
			if(mn>b[i].w){
				minn=mn;
				mini=mi;
				mi=i;
				mn=b[i].w;
			}
			else if(minn>b[i].w)minn=b[i].w,mini=i;
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(!flag&&i!=mi&&b[i].w+w+mn<a[head[i]].w){
				flag=1;
				l-=a[head[i]].w-b[i].w-w-mn;
				head[i]=a[head[i]].nxt;
				add(i,mi,b[i].w+w+mn);
				add(mi,i,b[i].w+w+mn);
			}
			else if(!flag&&i==mi&&b[i].w+w+minn<a[head[i]].w){
				flag=1;
				l-=a[head[i]].w-b[i].w-w-minn;
				head[i]=a[head[i]].nxt;
//				printf("%d %d\n",head[i]);
				add(i,mini,b[i].w+w+minn);
				add(mini,i,b[i].w+w+minn);
			}
			else if(head[i]<=2*(n-1)&&flag&&i!=mi&&b[i].w+mn<a[head[i]].w){
//				printf("%d %d\n",i,head[i]);
				l-=a[head[i]].w-b[i].w-mn;
				head[i]=a[head[i]].nxt;
				add(i,mi,b[i].w+mn);
				add(mi,i,b[i].w+mn);
			}
			else if(head[i]<=2*(n-1)&&flag&&i==mi&&b[i].w+minn<a[head[i]].w){
				l-=a[head[i]].w-b[i].w-minn;
				head[i]=a[head[i]].nxt;
//				printf("%d %d\n",a[head[i]].w,l);
				add(i,mini,b[i].w+minn);
				add(mini,i,b[i].w+minn);
			}
//			printf("%lld\n",l);
		}
		
	}
	printf("%lld\n",l);
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
