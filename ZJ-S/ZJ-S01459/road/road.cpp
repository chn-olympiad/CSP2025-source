#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){//mention int/long long!!!
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}
void Designant(){//freopen!!!
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
const int MAX=1e6+1e5+11;
int n,m,k,c[15],a[15][MAX],cnt;
long long ans=1e17;
int fa[MAX];
struct node{
	int x,y,w;
	node(int a,int b,int c){
		x=a,y=b,w=c;
	}
	node(){}
}edge[MAX],gf[MAX];
void reset(int x){
	for(int i=1;i<=x;i++)fa[i]=i;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return ;
	fa[x]=y;
}
bool ask(int x,int y){
	return find(x)==find(y);
}
bool flagA=1;
int main(){
	Designant();
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		edge[++cnt]=node(u,v,w);
		gf[cnt]=edge[cnt];
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		bool flag=0;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			if(a[i][j]==0)flag=1;
		}
		if(c[i]!=0||flag==0)flagA=0;
	}
	if(k==0){
		ans=0;
		reset(n);
		sort(edge+1,edge+cnt+1,[](node &x,node &y){
			return x.w<y.w;
		});
		for(int i=1,num=0,u,v,w;i<=m&&num<n;i++){
			u=edge[i].x,v=edge[i].y,w=edge[i].w;
			if(ask(u,v))continue;
			ans+=w;
			merge(u,v);
			num++;
		}
	}else if(flagA){
		ans=0;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				edge[++cnt]=node(n+i,j,a[i][j]);
			}
		}
		reset(n+k);
		sort(edge+1,edge+cnt+1,[](node &x,node &y){
			return x.w<y.w;
		});
		for(int i=1,num=0,u,v,w;i<=cnt&&num<n+k;i++){
			u=edge[i].x,v=edge[i].y,w=edge[i].w;
			if(ask(u,v))continue;
			ans+=w;
			merge(u,v);
			num++;
		}
	}else if(k<=10){
		int ctt=cnt;
		for(int f=0;f<(1<<k);f++){
			cnt=ctt;
			ll sum=0;
			for(int i=1;i<=k;i++){
				if(((f>>(i-1))&1)==0){
					edge[++cnt]=node(n+i,1,0);
					continue;
				}
				sum+=c[i];
				for(int j=1;j<=n;j++){
					edge[++cnt]=node(n+i,j,a[i][j]);
				}
			}
			for(int i=1;i<=m;i++)edge[i]=gf[i];
			memset(fa,0,sizeof(fa));
			reset(n+k);
			sort(edge+1,edge+cnt+1,[](node &x,node &y){
				return x.w<y.w;
			});
			for(int i=1,num=0,u,v,w;i<=cnt&&num<n+k;i++){
				u=edge[i].x,v=edge[i].y,w=edge[i].w;
				if(ask(u,v))continue;
				sum+=w;
				merge(u,v);
				num++;
			}
			ans=min(ans,sum);
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
