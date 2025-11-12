#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000000;
struct Node{
	long long x,y,z;
};
Node data1[MAXN];
long long t,n,ans,vis[MAXN],cnt[10];
vector<long long> v;
bool compare(const long long &x,const long long &y);
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while (t --){
		scanf("%lld",&n);
		v.clear();
		ans = cnt[1] = cnt[2] = cnt[3] = 0;
		for (long long i = 1;i <= n;i ++){
			scanf("%lld %lld %lld",&data1[i].x,&data1[i].y,&data1[i].z);
			if (data1[i].x >= data1[i].y && data1[i].x >= data1[i].z){
				vis[i] = 1;
				cnt[1] ++;
				ans += data1[i].x;
			} else if (data1[i].y >= data1[i].x && data1[i].y >= data1[i].z){
				vis[i] = 2;
				cnt[2] ++;
				ans += data1[i].y;
			} else if (data1[i].z >= data1[i].x && data1[i].z >= data1[i].y){
				vis[i] = 3;
				cnt[3] ++;
				ans += data1[i].z;
			}
		}
		if (cnt[1] > (n >> 1)){
			for (long long i = 1;i <= n;i ++){
				if (vis[i] == 1){
					v.push_back(max(data1[i].y,data1[i].z) - data1[i].x);
				}
			}
			
		} else if (cnt[2] > (n >> 1)){
			for (long long i = 1;i <= n;i ++){
				if (vis[i] == 2){
					v.push_back(max(data1[i].x,data1[i].z) - data1[i].y);
				}
			}
		} else if (cnt[3] > (n >> 1)){
			for (long long i = 1;i <= n;i ++){
				if (vis[i] == 3){
					v.push_back(max(data1[i].x,data1[i].y) - data1[i].z);
				}
			}
		} else {
			printf("%lld\n",ans);
			continue;
		}
		sort(v.begin(),v.end(),compare);
		for (long long i = 0;i < max(max(cnt[1],cnt[2]),cnt[3]) - (n >> 1);i ++){
			ans += v[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
bool compare(const long long &x,const long long &y){
	return x > y;
}
