#include<bits/stdc++.h>
using namespace std;
const int M=1e6+3;
long long ans;
int n,m,k,cnt[10003];
struct node{
	int u,v,w;
};
node bi[M];
int vis[10003];
bool cmp(node a,node b){
	return a.w>b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> bi[i].u >> bi[i].v >> bi[i].w;
		cnt[bi[i].u]++;
		cnt[bi[i].v]++;
	}
	sort(bi+1,bi+m+1,cmp);
	for(int i=1;i<=m;i++){
		int uu=bi[i].u,vv=bi[i].v;
		if(cnt[uu]==1 || cnt[vv]==1){
			cnt[uu]--,cnt[vv]--;
		}
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			int uu=bi[i].u,vv=bi[i].v;
			if(cnt[uu]>1 && cnt[vv]>1){
				cnt[uu]--;
				cnt[vv]--;
			}
			else{
				ans+=bi[i].w;
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
} 
