#include<bits/stdc++.h>
using namespace std;
struct association {
	long long val,id;
	bool operator < (association c) {
		return val<c.val;
	}
} sum[10];
long long n,a[100010][4],ans = 0,t,b[10];
vector<pair<long long,long long> > club[10];
inline bool cmp(pair<long long,long long> a,pair<long long,long long> b) {
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%lld",&t);
	while(t--) {
		ans = 0;
		for(int i = 1;i<=3;i++) club[i].clear(),sum[i].val = 0,b[i] = 0;
		scanf("%lld",&n);
		for(int i = 1; i<=n; i++) {
			scanf("%lld %lld %lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int i = 1; i<=n; i++) {
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) club[1].push_back({max(a[i][2]-a[i][1],a[i][3]-a[i][1]),i}),sum[1].val++,ans+=a[i][1];
			else {
				if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) club[2].push_back({max(a[i][1]-a[i][2],a[i][3]-a[i][2]),i}),sum[2].val++,ans+=a[i][2];
				else {
					if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])club[3].push_back({max(a[i][1]-a[i][3],a[i][2]-a[i][3]),i}),sum[3].val++,ans+=a[i][3];
				}
			}
		}
		sum[1].id = 1,sum[2].id = 2,sum[3].id = 3;
		sort(sum+1,sum+3+1);
		for(int i = 3; i>=1; i--){
			if(sum[i].val>n/2) {
				b[sum[i].id] = 1;
				sort(club[sum[i].id].begin(),club[sum[i].id].end(),cmp);
				for(auto y : club[sum[i].id]){ 
					for(int k = 1; k<=3; k++){
						if(sum[k].id==sum[i].id||b[sum[k].id]) continue;
						if(y.first==a[y.second][sum[k].id]-a[y.second][sum[i].id]) {
							sum[i].val--;
							sum[k].val++,ans+=y.first;
							break;
						}
					}
					if(sum[i].val<=n/2) break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
