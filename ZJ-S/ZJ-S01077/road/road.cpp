#include<bits/stdc++.h>
using namespace std;
const int N1=1E4+20,N2=1E6+10;
const long long INF=0x3f3f3f3f3f3f3f3f;
int c[12],t=0;
int pre[N1];
long long a[12][N1],d[N1];
bool f[N1];
struct S{
	int u,v,ne;
	long long w;
}e[N2*2];
typedef pair<int,int> PI;
typedef pair<long long,pair<int,PI> > PLI;
priority_queue<PLI,vector<PLI>,greater<PLI> > q1;
void f1(int u,int v,long long w){
	e[++t].u=u;
	e[t].v=v;
	e[t].w=w;
	e[t].ne=pre[u];
	pre[u]=t;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,i,j;
	long long c1,ans=INF;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++){
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		f1(u,v,w);
		f1(v,u,w);
	}
	for(i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	for(int x=0;x<(1<<k);x++){
		memset(d,0x3f,sizeof(d));
		memset(f,0,sizeof(f));
		c1=0;
		for(i=1;i<=k;i++){
			if(x&(1<<(i-1))) c1+=c[i];
		}
		d[1]=0;
		q1.push({d[1],{1,{0,0}}});
		while(!q1.empty()){
			long long l1=q1.top().first;
			int h=q1.top().second.first;
			int a1=q1.top().second.second.first,b1=q1.top().second.second.second;
			q1.pop();
			if(f[h]) continue;
			f[h]=true;
			if(h<=n){
				if(a1==2) c1+=e[b1].w;
				else if(a1==1) c1+=a[b1][h];
				for(i=pre[h];i;i=e[i].ne){
					if(!f[e[i].v]&&l1+e[i].w<d[e[i].v]){
						d[e[i].v]=l1+e[i].w;
						q1.push({d[e[i].v],{e[i].v,{2,i}}});
					}
				}
				for(i=1;i<=k;i++){
					if(!f[i+n]&&(x&(1<<(i-1)))&&l1+a[i][h]<d[i+n]){
						d[i+n]=l1+a[i][h];
						q1.push( { d[i+n] , { i+n , {1,h} } } );
					}
				}
			}
			else{
				h-=n;
				if(a1==1) c1+=a[h][b1];
				for(i=1;i<=n;i++){
					if(!f[i]&&l1+a[h][i]<d[i]){
						d[i]=l1+a[h][i];
						q1.push( { d[i], {i, {1,h} } } );
					}
				}
			}
		}
		ans=min(ans,c1);
	}
	printf("%lld",ans);
	return 0;
}
