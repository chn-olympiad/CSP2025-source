#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int k,n,m,vis[1000001],fa[1000001];
long long c[11],a[100001][11];
long long ans=1e18,tmp;
struct ed {
	int x,y;
	long long w;
} e[1000001];
vector<ed>s;
int gtf(int x) {
	if(fa[x]==x)return x;
	return fa[x]=gtf(fa[x]);
}
bool cmp(ed al,ed bt){
	return al.w<bt.w;
}
void kurs(){
	int it=0;
	while(it<(int)s.size()){
		ed te=s[it];
		it++;
		int al,bt;
		al=gtf(te.x);
		bt=gtf(te.y);
//		cout<<al<<" "<<bt<<" "<<te.w<<" "<<tmp<<endl;
		if(al==bt)continue;
		tmp+=te.w;
		fa[bt]=al;
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		scanf("%d%d%lld",&e[i].x,&e[i].y,&e[i].w);
	}
	for(int i=1; i<=k; i++) {
		scanf("%lld",&c[i]);
		for(int j=1; j<=n; j++) {
			scanf("%lld",&a[j][i]);
		}
	}
	for(int i=0; i<(1<<k); i++) {
		for(int j=1;j<=n+k;j++)fa[j]=j;
		s.clear();
		for(int j=1; j<=m; j++) {
			s.push_back(e[j]);
		}
		tmp=0;
		for(int j=1; j<=k; j++) {
			if((i>>(j-1))&1) {
				tmp+=c[j];
				for(int l=1; l<=n; l++) {
					s.push_back(ed {n+j,l,a[l][j]});
				}
			}
		}
		sort(s.begin(),s.end(),cmp);
		kurs();
		ans=min(ans,tmp);
//		cout<<i<<" "<<ans<<" "<<s.size()<<endl;
	}
	printf("%lld",ans);
	return 0;
}
