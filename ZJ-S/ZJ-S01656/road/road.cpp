#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+50,M=2e6+5,INF=1e16;
long long n,m,k,dm[12],l[20],ans,mn=INF,fa[N],cnt,rn;
struct edge{
	long long u,v,w,id;
}e[M];
inline bool cmp(edge x,edge y){
	return x.w<y.w;
}
inline long long find(long long x){
	return fa[x]=fa[x]==x?fa[x]:find(fa[x]);
}
inline void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].id=0;
	}
	for(int i=1;i<=k;i++){
		cin>>l[i];
		for(int j=1;j<=n;j++){
			m++;
			e[m].u=n+i;
			e[m].v=j;
			cin>>e[m].w;
			e[m].id=i;
		}
	}
	sort(e+1,e+m+1,cmp);
	while(dm[k+1]==0){
		rn=n;
		ans=0;
		int j=1;
		while(dm[j]==1) j++;
		dm[j]=1;
		for(int i=j-1;i>0;i--) dm[i]=0;
		for(int i=1;i<=k;i++) if(dm[i]) rn++,ans+=l[i];
		for(int i=1;i<=n+k;i++) fa[i]=i;
		cnt=0;
		for(int i=1;i<=m;i++){
			long long X=find(e[i].u),Y=find(e[i].v);
			if(!dm[e[i].id]&&e[i].id>0) continue;
			if(X==Y) continue;
			fa[X]=Y;
			cnt++;
			ans+=e[i].w;
			if(cnt==rn-1){
				mn=min(ans,mn);
				break;
			}
		}
	}
	cout<<mn<<'\n';
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

