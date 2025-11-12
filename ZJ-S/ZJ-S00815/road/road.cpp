#include<bits/stdc++.h>
#define maxm 6000010
#define maxn 1000010
#define ll long long
using namespace std;
struct ppp{
	int u,v;
	ll w;
}e[maxm],te[maxm];
int n,m,tn,cnt,k;
//int to[maxm],nxt[maxm],head[maxn];
int f[maxn];
bool flag=1;
ll c[15],a[15][maxn];
//void add(int u,int v,int w){
//	to[++t]=v;
//	nxt[t]=head[u];
//	head[u]=t;
//	val[t]=w;
//}
bool cmp(ppp x,ppp y){
	return x.w<y.w;
}
bool cmp2(int x,int y){
	return x>y;
}
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}		
	ll res=0;
	if(k==0){
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx!=fy){
				f[fy]=fx;
				res+=e[i].w;
			}
			if(cnt==n-1) break;		
		}
		cout<<res;
		return 0;	
	}
	else if(flag){
		int tm=m,tn=n;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++m].u=j,e[m].v=n+i,e[m].w=a[i][j];
			}
		}		
		for(int i=n+1;i<=n+k;i++) f[i]=i;
		n+=k;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx!=fy){
				f[fy]=fx;
				res+=e[i].w;
			}
			if(cnt==n-1) break;		
		}
		cout<<res;
		return 0;
	}
	else{
		ll ans=1145141919810ll;
		for(int T=0;T<=(1<<k)-1;T++){
			for(int i=1;i<=m;i++) te[i]=e[i];
			int kcnt=0,tn=n,tm=m;
			res=0,cnt=0;
			for(int i=1;i<=k;i++){
				if((T>>(i-1))&1){
					res+=c[i],kcnt++;
					for(int j=1;j<=tn;j++){
						te[++tm].u=j,te[tm].v=tn+kcnt,te[tm].w=a[i][j];
					}
				}
			}	
			for(int i=1;i<=tn+kcnt;i++) f[i]=i;
			tn+=kcnt;
			sort(te+1,te+tm+1,cmp);
			for(int i=1;i<=tm;i++){
				int fx=find(te[i].u),fy=find(te[i].v);
				if(fx!=fy){
					f[fy]=fx;
					res+=te[i].w;
				}
				if(cnt==tn-1) break;		
			}
			ans=min(res,ans);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
/*
5 6 0
1 3 1
2 3 3
3 4 7
3 5 2
1 4 5
2 5 6

4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
*/