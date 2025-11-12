#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define mkp make_pair
const int inf=2e15;
int n,m,k;
struct EDGE{
	int u,v,w;
}e[2010000];
int ne[101000];
int tot; 
priority_queue<pair<int,int> >pq;
int fa[10100];
int fnd(int x){
	if(x==fa[x]) return x;
	return fa[x]=fnd(fa[x]);
}
int sum,ans=inf;
void clea(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
}
void gtans(){
	ans=min(sum,ans);
	sum=0;
}
int a[13][10100],c[13];
int now[10100];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	/*system("fc road.out road3.ans");*/
	//cin>>n>>m>>k;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		//cin>>e[i].u>>e[i].v>>e[i].w;
		scanf("%lld %lld %lld",&e[i].u,&e[i].v,&e[i].w);
		pq.push(mkp(-e[i].w,i));
	}
	clea();
	while(!pq.empty()){
		int id=pq.top().S,val=-pq.top().F;pq.pop();
		int fx=fnd(e[id].u),fy=fnd(e[id].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		sum+=val;
		ne[++tot]=id;
	}//cout<<tot<<"\n";
	gtans();
	for(int i=1;i<=k;i++){
		//cin>>c[i];
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			//cin>>a[i][j];
			scanf("%lld",&a[i][j]);
			e[m+i*n-n+j].u=n+i;
			e[m+i*n-n+j].v=j;
			e[m+i*n-n+j].w=a[i][j];
		}
	}
	int Sit=(1<<k)-1;
	for(int res=1;res<=Sit;res++){
		for(int i=1;i<=n;i++) now[i]=inf;
		for(int i=1;i<=k;i++){
			if((res>>(i-1))&1){
				sum+=c[i];
				for(int j=1;j<=n;j++){
					pq.push(mkp(-a[i][j],m+i*n-n+j));
				}
			}
		}
		for(int i=1;i<=tot;i++){
			pq.push(mkp(-e[ne[i]].w,ne[i]));
		}clea();
		while(!pq.empty()){
			int id=pq.top().S,val=-pq.top().F;pq.pop();
			int fx=fnd(e[id].u),fy=fnd(e[id].v);
			if(fx==fy) continue;
			fa[fx]=fy;
			sum+=val;
			
		} gtans();
	}cout<<ans<<"\n";
 	return 0;
}
