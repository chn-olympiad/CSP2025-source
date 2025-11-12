#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#define N 1000010
using namespace std;
long long fa[N],dis[N][20];
long long n,m,k,c[20],ans=0,aflag=1;
long long find(long long k){
	if(fa[k]==k){
		return k;
	}
	return fa[k]=find(fa[k]);
}
void merge(long long x,long long y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[y]=x;
		for(int i=1;i<=k;++i){
			dis[x][i]=min(dis[x][i],dis[y][i]);		
		}
	}
}
struct node{
	long long u,v,w;
}a[N];
bool cmp(node x,node y){
	return x.w<=y.w;
}
inline long long read(){
	char c='&';
	while(!(c>='0'&&c<='9')){
		c=getchar();
	}
	long long sumt=0;
	while((c>='0'&&c<='9')){
		sumt=(sumt<<3)+(sumt<<1)+c-'0';
		c=getchar();
	}
	return sumt;
}
long long aij[30][10010];
void solvea(){
	long long tot=m;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			if(aij[i][j]==0){
				for(int o=1;o<=n;++o){
					if(o==j){
						continue;
					}
					a[++tot].u=j;
					a[tot].v=o;
					a[tot].w=aij[i][o];
				}
				break;
			} 
		}
	}
	sort(a+1,a+1+tot,cmp);
	long long cnt=0;
	for(int i=1;i<=m&&cnt<n-1;++i){
		long long t1=find(a[i].u),t2=find(a[i].v);
		if(t1!=t2){
			++cnt;
			merge(t1,t2);
			ans+=a[i].w;
		}
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;++i){
		c[i]=read();
		aflag=aflag&&c[i]==0;
		bool aflagg=0;
		for(int j=1;j<=n;++j){
			dis[j][i]=aij[i][j]=read();
			aflagg=aflagg||aij[i][j]==0;
		}
		aflag=aflag&&aflagg;
	}
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	long long cnt=0;
	for(int i=1;i<=m&&cnt<n-1;++i){
		long long t1=find(a[i].u),t2=find(a[i].v);
		if(t1!=t2){
			++cnt;
			long long cost=a[i].w,minn=1145141919810,minw=-1;
			for(int j=1;j<=k;++j){
				if(minn>=c[j]+dis[t1][j]+dis[t2][j]){
					minn=c[j]+dis[t1][j]+dis[t2][j];
					minw=j;
				}	
			}
			if(minn<=cost){
				cost=minn;
				c[minw]=dis[t1][minw]=dis[t2][minw]=0;
			}
			merge(t1,t2);
			ans+=cost;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
*/
