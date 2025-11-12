#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt[4];
int a[100010][4];
struct Nd{
	int cz1,cz2,i;
};
bool cmp(Nd a,Nd b){
	if (a.cz1 == b.cz1){
		return a.cz2 > b.cz2;
	}
	return a.cz1 > b.cz1;
}
struct N{
	int i,x;
};
bool cp(N a,N b){
	return a.x > b.x;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int ans = 0;
		memset(cnt,0,sizeof(cnt));
		memset(a,0,sizeof(a));
		int n;
		cin >> n;
		vector<Nd> b;
		for (int i = 0; i < n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int maxn = max(max(a[i][1],a[i][2]),a[i][3]);
			int minn = min(min(a[i][1],a[i][2]),a[i][3]);
			int mid = a[i][1] + a[i][2] + a[i][3] - maxn - minn;
			b.push_back({maxn - mid,mid - minn,i});
		}
		sort(b.begin(),b.end(),cmp);
		for (int j = 0; j < n; j++){
			int i = b[j].i;
			vector<N> c;
			c.push_back({1,a[i][1]});
			c.push_back({2,a[i][2]});
			c.push_back({3,a[i][3]});
			sort(c.begin(),c.end(),cp);
			if (cnt[c[0].i] == n / 2){
				if (cnt[c[1].i] == n / 2){
//					cout << c[2].i << ' ';
					ans += a[i][c[2].i];
					cnt[c[2].i]++;
				}
				else{
//					cout << c[1].i << ' ';
					ans += a[i][c[1].i];
					cnt[c[1].i]++;
				}
			}
			else{
//				cout << c[0].i << ' ';
				ans += a[i][c[0].i];
				cnt[c[0].i]++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
