#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define int long long
#define N 500100
#define ll long long
int n,rgcnt=0;
ll k,a[N],pre[N];
unordered_map< int,vector<int> > mp;
struct Range{
	int l,r;
}ra[N];
bool cmp(Range x,Range y){
	if(x.r!=y.r)return x.r<y.r;
	return x.l<y.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
//		printf("%d:i:%d,dis:%d\n",i,pre[i],pre[i]^k);
		mp[pre[i]^k].emplace_back(i);
	}
	int tmp=0;
	for(int i=1;i<=n;++i){
		tmp=pre[i-1];
		if(mp.count(tmp)){
			auto it=upper_bound(mp[tmp].begin(),mp[tmp].end(),i-1);
			if(it==mp[tmp].end()) continue;
			ra[++rgcnt]=Range{i,(*it)};
		}
	}
//	for(int i=1;i<=rgcnt;++i){
//		printf("%d~%d\n",ra[i].l,ra[i].r);
//	}
	sort(ra+1,ra+1+rgcnt,cmp);
	ll las=0,j=1,ans=0;
	while(j<n){
		while(j<n&&ra[j].l<=las) ++j;
		if(ra[j].r>las){
			las=ra[j].r;
			ans++;
		}
		else break;
	}
	cout<<ans;
	return 0;
}
