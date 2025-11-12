#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define _F(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
int read(){
	int p=0,f=1;char ch=getchar();
	while(!isdigit(ch))
		f=ch=='-'?-1:1,ch=getchar();
	while(isdigit(ch))
		p=p*10+ch-'0',ch=getchar();
	return p*f;
}
const int N=1e4+5,M=1e6+5;
int n,m,k,ans;
struct qwe{
	int x,y,v;
}e1[M],e[M],ec[M];
int ent,cnt;
int c[12],a[12][N],f[N];
bool operator <(const qwe x,const qwe y){
	return x.v<y.v;
}
int find(int x){
	return f[x]=x==f[x]?f[x]:find(f[x]);
}
void kruskal(){
	sort(e1+1,e1+m+1);
	F(i,1,n)
		f[i]=i;
	F(i,1,m){
		int x=e1[i].x,y=e1[i].y;
		x=find(x),y=find(y);
		if(x!=y){
			e[++ent]={e1[i].x,e1[i].y,e1[i].v};
			f[x]=y;
			ans+=e1[i].v;
//			printf("%d ",e1[i].v);
		}
	}
	return;
}
int krus(){
	int ret=0;
	sort(e+1,e+cnt+1);
	F(i,1,n+k)
		f[i]=i;
	F(i,1,cnt){
		int x=e[i].x,y=e[i].y;
		x=find(x),y=find(y);
		if(x!=y){
			ret+=e[i].v;
			f[x]=y;
		}
	}
	return ret;
}
void add(int x){
	F(i,1,n){
		e[++cnt]={x+n,i,a[x][i]};
	}
}
signed main()
{
 freopen("road.in","r",stdin);
 freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	F(i,1,m){
		int x=read(),y=read(),z=read();
		e1[i]={x,y,z};
	}
	F(i,1,k){
		c[i]=read();
		F(j,1,n){
			a[i][j]=read();
		}
	}
	kruskal();
	F(i,1,ent){
		ec[i]={e[i].x,e[i].y,e[i].v};
	}
	for(int i=1;i<(1<<k);i++){
		cnt=ent;
		F(i,1,ent){
			e[i]={ec[i].x,ec[i].y,ec[i].v};
		}
		int tmp=0;
		for(int j=i,u=1;j;j/=2,u++){
			if(j%2==1){
				tmp+=c[u];
				add(u);
			}
		}
		tmp+=krus();
		ans=min(ans,tmp);
	}
	printf("%lld",ans);
   return 0;
}

