#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> g[4];
int a[100005][5];
signed main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n,res = 0;
		for(int i = 1; i <= 3; i++) g[i].clear();
		scanf("%lld",&n);
		for(int i = 1; i <= n; i++){
			int maxn = -1,maxm = -1,pl;
			for(int j = 1; j <= 3; j++){
				scanf("%lld",&a[i][j]);
				if(a[i][j] > maxn){
					pl = j;
					maxm = maxn;
					maxn = a[i][j];
				}else if(a[i][j] > maxm){
					maxm = a[i][j];
				}
			}
			res += maxn;
			g[pl].push_back({maxn - maxm});
		}
		for(int i = 1; i <= 3; i++){
			if(g[i].size() > n / 2){
				int cha = g[i].size() - n / 2;
				sort(g[i].begin(),g[i].end());
				for(int j = 0; j < cha; j++) res -= g[i][j];
				break;
			}
		}
		printf("%lld\n",res);
	} 
	return 0;
}
