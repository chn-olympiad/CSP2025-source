#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 500;
int n,a[N][5],cst[N];
vector<int> gr[5];
int T;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> T;
	while(T --){
		int ans = 0;
		cin >> n;
		for(int i = 1;i <= 3;i ++)gr[i].clear();
		for(int i = 1;i <= n;i ++){
			vector<pair<int,int>> tmp;
			for(int j = 1;j <= 3;j ++){
				cin >> a[i][j];
				tmp.push_back(pair<int,int>{a[i][j],j});
			}
			sort(tmp.begin(),tmp.end());
			reverse(tmp.begin(),tmp.end());
			gr[tmp[0].second].push_back(i);
			ans += a[i][tmp[0].second];
			cst[i] = tmp[0].first - tmp[1].first;
		}
		int maxsz = 0,id = 0;
		for(int i = 1;i <= 3;i ++){
			if(maxsz <= (int)gr[i].size()){
				maxsz = (int)gr[i].size();
				id = i;
			}
		}
		if(maxsz <= n / 2){
			cout << ans << endl;
			continue;
		}
		int delta = maxsz - (n / 2);
		sort(gr[id].begin(),gr[id].end(),[](int x,int y){
			return (cst[x] == cst[y]) ? (x < y) : (cst[x] < cst[y]);
		});
		for(int i = 0;i < delta;i ++){
			ans -= cst[gr[id][i]];
		}
		cout << ans << endl;
	}
	return 0;
}
