#include <bits/stdc++.h>
using namespace std;
int t;
struct node{
	int a, num, dist;
}club1[200005], club2[200005], club3[200005];
bool cmp(node x, node y){
	return x.a > y.a;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--){
		int n;
		vector<int> point(4, 0);
		vector<int> summ(4, 0);
		vector<int> vis(200005, 0);
		cin >> n;
		for(int i = 1; i <= n; i++){
			club1[i].num = i;
			club2[i].num = i;
			club3[i].num = i;
			cin >> club1[i].a >> club2[i].a >> club3[i].a;
		}
		int maxx = n / 2;
		sort(club1 + 1, club1 + n + 1, cmp);
		sort(club2 + 1, club2 + n + 1, cmp);
		sort(club3 + 1, club3 + n + 1, cmp);
		int ans[4] = {};
		int fa = 0, f = 0;
		for(int i = 1; i <= n; i++){
			if(club2[i].a == 0) fa++;
			if(club3[i].a == 0) f++;
		}
		int result = 0;
		if(fa == n and f == n){
			for(int i = 1; i <= n / 2; i++) result += club1[i].a;
			cout << result << endl;
		}
		if(f == n and fa != n){
			while(point[1] + point[2] != n){
				node f[4] = {};
				int flag = 0;
				if(point[1] + 1 <= maxx) f[++flag].a = club1[summ[1] + 1].a, f[flag].num = club1[summ[1] + 1].num, f[flag].dist = 1;
				if(point[2] + 1 <= maxx) f[++flag].a = club2[summ[2] + 1].a, f[flag].num = club2[summ[2] + 1].num, f[flag].dist = 2;
				for(int i = 1; i <= flag; i++){
					summ[f[i].dist]++;
					if(!vis[f[i].num]){
						vis[f[i].num] = 1;
						ans[f[i].dist] += f[i].a;
						point[f[i].dist]++;
					}
				}
			}
			for(int i = 1; i <= 3; i++){
				result += ans[i];
			}
			cout << result << endl; 
		}
		while(point[1] + point[2] + point[3] != n){
			node f[4] = {};
			int flag = 0;
			if(point[1] + 1 <= maxx) f[++flag].a = club1[summ[1] + 1].a, f[flag].num = club1[summ[1] + 1].num, f[flag].dist = 1;
			if(point[2] + 1 <= maxx) f[++flag].a = club2[summ[2] + 1].a, f[flag].num = club2[summ[2] + 1].num, f[flag].dist = 2;
			if(point[3] + 1 <= maxx) f[++flag].a = club3[summ[3] + 1].a, f[flag].num = club3[summ[3] + 1].num, f[flag].dist = 3;
			sort(f + 1, f + flag + 1, cmp);
			for(int i = 1; i <= flag; i++){
				summ[f[i].dist]++;
				if(!vis[f[i].num]){
					vis[f[i].num] = 1;
					ans[f[i].dist] += f[i].a;
					point[f[i].dist]++;
				}
			}
		}
		if(fa != n and f != n){
			for(int i = 1; i <= 3; i++){
				result += ans[i];
			}
			cout << result << endl; 
		}
	}
	return 0;
}
