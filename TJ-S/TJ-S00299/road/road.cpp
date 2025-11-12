#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define RLL register LL
#define PLL pair<LL,LL>
const LL N=1e4+10,M=1e6+10;
LL n,m,k,a[11],fa[N],num,maxx,ans;
bool choose[M];

struct NODE{
	LL u,v,w;
	inline bool operator < (const NODE nx) const{
		return w<nx.w;
	}
} e[M];

inline LL find_fa(LL x){
	return (fa[x]==x?x:fa[x]=find_fa(fa[x]));
}

struct NODE2{
	priority_queue<NODE> q;
} country[11];

inline void unit(){
	for(RLL i=1;i<=n+k;++i){
		fa[i]=i;
	}
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	unit();
	for(RLL i=1;i<=m;++i){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(RLL i=1;i<=k;++i){
		cin>>a[i];
		for(RLL j=1;j<=n;++j){
			LL w;
			cin>>w;
			country[i].q.push({i+n,j,-w});
		}
	}
	sort(e+1,e+m+1);
	for(RLL i=1,cnt=1;cnt<n;++i){
		LL x=find_fa(e[i].u),y=find_fa(e[i].v);
		if(x!=y){
			num+=e[i].w;
			maxx=e[i].w;
			choose[i]=true;
			++cnt;
			fa[x]=y;
		}
	}
	for(RLL i=1,j=1;j<n;++i){
		if(choose[i]){
			e[j++]=e[i];
		}
	}
	ans=num;
	for(RLL i=1;i<(1<<k);++i){
		unit();
		NODE2 x[11];
		num=0;
		LL cnt=0;
		for(RLL j=1;j<=k;++j){
			if(i&(1<<(j-1))){
				num+=a[j];
				x[++cnt].q=country[j].q;
			}
		}
		for(RLL j=1,count=1;count<n+cnt;){
			LL minx=0;
			for(RLL ij=1;ij<=cnt;++ij){
				while(x[ij].q.size() && find_fa(x[ij].q.top().u)==find_fa(x[ij].q.top().v)){
					x[ij].q.pop();
				}
				if(x[ij].q.size() && (!minx || -x[ij].q.top().w<-x[minx].q.top().w)){
					minx=ij;
				}
			}
			while(j<n && find_fa(e[j].u)==find_fa(e[j].v)){
				++j;
			}
			if(minx && -x[minx].q.top().w<e[j].w){
				num-=x[minx].q.top().w;
				fa[find_fa(x[minx].q.top().u)]=find_fa(x[minx].q.top().v);
				x[minx].q.pop();
			}else{
				num+=e[j].w;
				fa[find_fa(e[j].u)]=find_fa(e[j].v);
				++j;
			}
			++count;
		}
		ans=min(ans,num);
	}
	cout<<ans;
	return 0;
}
