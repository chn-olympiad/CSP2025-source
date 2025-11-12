#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int v1[N], v2[N], v3[N], now[N], n, a1[N], a2[N], a3[N], m1, m2, m3;
bool cmp1(int x, int y){
	int w1 = v1[x] - max(v2[x], v3[x]), w2 = v1[y] - max(v2[y], v3[y]);
	return w1 > w2;
}
bool cmp2(int x, int y){
	int w1 = v2[x] - max(v1[x], v3[x]), w2 = v2[y] - max(v1[y], v3[y]);
	return w1 > w2;
}
bool cmp3(int x, int y){
	int w1 = v3[x] - max(v1[x], v2[x]), w2 = v3[y] - max(v1[y], v2[y]);
	return w1 > w2;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;cin >> T;
	while(T --){
		cin >> n;
		for(int i = 1;i <= n;i ++)cin >> v1[i] >> v2[i] >> v3[i];
		for(int i = 1;i <= n;i ++){
			if(v1[i] >= v2[i] && v1[i] >= v3[i]){
				a1[++ m1] = i;
			}
			else if(v2[i] >= v1[i] && v2[i] >= v3[i]){
				a2[++ m2] = i;
			}
			else a3[++ m3] = i;
		}
		sort(a1 + 1, a1 + m1 + 1, cmp1);
		sort(a2 + 1, a2 + m2 + 1, cmp2);
		sort(a3 + 1, a3 + m3 + 1, cmp3);
		int s = n / 2;
		if(m1 > s){
			for(int i = s + 1;i <= m1;i ++){
				if(v2[a1[i]] >= v3[a1[i]])a2[++ m2] = a1[i];
				else a3[++ m3] = a1[i];
			}
			m1 = s;
		}
		else if(m2 > s){
			for(int i = s + 1;i <= m2;i ++){
				if(v1[a2[i]] >= v3[a2[i]])a1[++ m2] = a2[i];
				else a3[++ m3] = a2[i];
			}
			m2 = s;
		}
		else if(m3 > s){
			for(int i = s + 1;i <= m3;i ++){
				if(v1[a3[i]] >= v2[a3[i]])a1[++ m1] = a3[i];
				else a2[++ m2] = a3[i];
			}
			m3 = s;
		}
		int ans = 0;
		for(int i = 1;i <= m1;i ++)ans += v1[a1[i]];
		for(int i = 1;i <= m2;i ++)ans += v2[a2[i]];
		for(int i = 1;i <= m3;i ++)ans += v3[a3[i]];
//		for(int i = 1;i <= m1;i ++)cout << a1[i] << ' ';
//		cout << '\n';
//		for(int i = 1;i <= m2;i ++)cout << a2[i] << ' ';
//		cout << '\n';
//		for(int i = 1;i <= m3;i ++)cout << a3[i] << ' ';
//		cout << '\n';
		cout << ans << '\n';
		m1 = m2 = m3 = 0;
	}
	return 0;
}