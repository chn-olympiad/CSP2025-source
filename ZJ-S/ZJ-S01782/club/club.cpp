#include <bits/stdc++.h>
using namespace std;

int T, n, ans;

struct node{
	int c[3];
} a[100010];

bool cmp(node x, node y){
	node tx = x, ty = y;
	sort(tx.c, tx.c+3);
	sort(ty.c, ty.c+3);
	return (tx.c[2]-tx.c[1]) < (ty.c[2]-ty.c[1]);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i].c[0] >> a[i].c[1] >> a[i].c[2];
		}
		vector<node> c[3];
		for(int i = 1; i <= n; i++){
			int maxx = max_element(a[i].c, a[i].c+3)-a[i].c;
			c[maxx].push_back(a[i]);
			ans += a[i].c[maxx];
		}
		bool flag = 0;
		if(c[0].size() > n / 2) flag = 1;
		else if(c[1].size() > n / 2){
			swap(c[0], c[1]);
			flag = 1;
		}
		else if(c[2].size() > n / 2){
			swap(c[0], c[2]);
			flag = 1;
		}
		if(flag){
			sort(c[0].begin(), c[0].end(), cmp);
			int csize = c[0].size();
			for(int i = 0; i < (csize - n/2); i++){
				sort(c[0][i].c, c[0][i].c+3);
				ans -= c[0][i].c[2]-c[0][i].c[1];
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
