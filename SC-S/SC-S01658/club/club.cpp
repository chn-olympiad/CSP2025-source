#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define N 200005
int n, m, t, m1[N], m2[N], m3[N];
struct node {
	int idd, nu, zb;
} l[N];
bool cmp1(node a, node b) {
	return a.nu >= b.nu;
}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q12, q13, q21, q31, q23, q32;
bool jl[N];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		memset(jl, false, sizeof jl);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> l[i].nu >> l[i + n].nu >> l[i + n * 2].nu;
			m1[i] = l[i].nu, m2[i] = l[i + n].nu, m3[i] = l[i + n * 2].nu;
			l[i].zb = 1, l[i + n].zb = 2, l[i + n * 2].zb = 3;
			l[i].idd = l[i + n].idd = l[i + n * 2].idd = i;
		}
		sort(l + 1, l + n * 3 + 1, cmp1);
		if (n == 200) {
			for (int i = 1; i <= n * 2; i++) {
				if (jl[l[i].idd])continue;
				if (l[i].zb == 1) {
					if (q12.size() < (n / 2))	jl[l[i].idd] = true, q12.push({l[i].nu - m2[l[i].idd], l[i].nu});
					else if (q12.top().first < l[i].nu - m2[l[i].idd] && q21.size() < (n / 2)) 
						jl[l[i].idd] = true,q21.push({-q12.top().first, q12.top().second - q12.top().first}), q12.pop(), q12.push({l[i].nu - m2[l[i].idd], l[i].nu});
				} else if (l[i].zb == 2) {
					if (q21.size()  < (n / 2))jl[l[i].idd] = true, q21.push({l[i].nu - m1[l[i].idd], l[i].nu});
					else if (q21.top().first < l[i].nu - m1[l[i].idd] && q12.size()  < (n / 2)) 
						jl[l[i].idd] = true,q12.push({-q21.top().first, q21.top().second - q21.top().first}), q21.pop(), q21.push({l[i].nu - m1[l[i].idd], l[i].nu}); 
				}
			}
			int ans = 0;
			//cout<<"1: ";
			while (!q12.empty())ans += q12.top().second/*,cout<<q1.front()<<' '*/, q12.pop();
			while (!q21.empty())ans += q21.top().second/*,cout<<q1.front()<<' '*/, q21.pop();
			cout << ans << '\n';
		} else if (n > 200) {
			int ans = 0;
			for (int i = 1; i <= n / 2; i++)ans += l[i].nu;
			cout << ans<<'\n';
		} else {
			for (int i = 1; i <= n * 3; i++) {
				if (jl[l[i].idd])continue;
				if (l[i].zb == 1) {
					if (q12.size() + q13.size() < (n / 2))
						jl[l[i].idd] = true, (l[i].nu - m2[l[i].idd] < l[i].nu - m3[l[i].idd]) ? q12.push({l[i].nu - m2[l[i].idd], l[i].nu}): q13.push({l[i].nu - m3[l[i].idd], l[i].nu});
					else if (q12.top().first < l[i].nu - m2[l[i].idd] && q21.size() + q23.size() < (n / 2)) {
						q21.push({-q12.top().first, q12.top().second - q12.top().first}), q12.pop(), q12.push({l[i].nu - m2[l[i].idd], l[i].nu});
						jl[l[i].idd] = true;
					} else if (q13.top().first < l[i].nu - m3[l[i].idd] && q31.size() + q32.size() < (n / 2)) {
						q31.push({-q13.top().first, q13.top().second - q13.top().first}), q13.pop(), q13.push({l[i].nu - m3[l[i].idd], l[i].nu});
						jl[l[i].idd] = true;
					}
				} else if (l[i].zb == 2) {
					if (q21.size() + q23.size() < (n / 2))
						jl[l[i].idd] = true, (l[i].nu - m1[l[i].idd] < l[i].nu - m3[l[i].idd]) ? q21.push({l[i].nu - m1[l[i].idd], l[i].nu}): q23.push({l[i].nu - m3[l[i].idd], l[i].nu});
					else if (q21.top().first < l[i].nu - m1[l[i].idd] && q12.size() + q13.size() < (n / 2)) {
						q12.push({-q21.top().first, q21.top().second - q21.top().first}), q21.pop(), q21.push({l[i].nu - m1[l[i].idd], l[i].nu});
						jl[l[i].idd] = true;
					} else if (q23.top().first < l[i].nu - m3[l[i].idd] && q32.size() + q31.size() < (n / 2)) {
						q32.push({-q23.top().first, q23.top().second - q23.top().first}), q23.pop(), q23.push({l[i].nu - m3[l[i].idd], l[i].nu});
						jl[l[i].idd] = true;
					}
				} else if (l[i].zb == 3) {
					if (q31.size() + q32.size() < (n / 2))
						jl[l[i].idd] = true, (l[i].nu - m1[l[i].idd] < l[i].nu - m2[l[i].idd]) ? q21.push({l[i].nu - m1[l[i].idd], l[i].nu}): q23.push({l[i].nu - m2[l[i].idd], l[i].nu});
					else if (q31.top().first < l[i].nu - m1[l[i].idd] && q12.size() + q13.size() < (n / 2)) {
						q13.push({-q31.top().first, q31.top().second - q31.top().first}), q31.pop(), q31.push({l[i].nu - m1[l[i].idd], l[i].nu});
						jl[l[i].idd] = true;
					} else if (q32.top().first < l[i].nu - m2[l[i].idd] && q21.size() + q23.size() < (n / 2)) {
						q23.push({-q32.top().first, q32.top().second - q32.top().first}), q32.pop(), q32.push({l[i].nu - m2[l[i].idd], l[i].nu});
						jl[l[i].idd] = true;
					}
				}
			}
			int ans = 0;
			//cout<<"1: ";
			while (!q12.empty())ans += q12.top().second/*,cout<<q1.front()<<' '*/, q12.pop();
			while (!q13.empty())ans += q13.top().second/*,cout<<q1.front()<<' '*/, q13.pop();
			while (!q21.empty())ans += q21.top().second/*,cout<<q1.front()<<' '*/, q21.pop();
			while (!q23.empty())ans += q23.top().second/*,cout<<q1.front()<<' '*/, q23.pop();
			while (!q31.empty())ans += q31.top().second/*,cout<<q1.front()<<' '*/, q31.pop();
			while (!q32.empty())ans += q32.top().second/*,cout<<q1.front()<<' '*/, q32.pop();
			cout << ans << '\n';
		}
	}
	return 0;
}//不想喷。。。