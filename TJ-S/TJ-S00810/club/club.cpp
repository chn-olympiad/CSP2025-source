#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e+5 + 5;
int a[maxn][3];

inline ll read() {
	ll ref = 0;
	bool f = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') f = 0;
		ch = getchar();
	}
	while(isdigit(ch))
		ref = (ref << 1) + (ref << 3) + (ch ^ 48), ch = getchar();
	return (f ? ref : -ref);
} 

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = read();
	while(t--) {
		int n = read(), cnt[3] = {}, answer = 0;
		priority_queue<int> q;
		for(int i = 1; i <= n; i++) {
			a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) cnt[0]++;
			if(a[i][1] > a[i][0] && a[i][1] >= a[i][2]) cnt[1]++;
			if(a[i][2] > a[i][0] && a[i][2] > a[i][1]) cnt[2]++;
			answer += max({a[i][0], a[i][1], a[i][2]});
		}
		int ma = 0;
		if(cnt[1] > cnt[ma]) ma = 1;
		if(cnt[2] > cnt[ma]) ma = 2;
		cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i = 1; i <= n; i++) {
			swap(a[i][0], a[i][ma]);
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) cnt[0]++;
			if(a[i][1] > a[i][0] && a[i][1] >= a[i][2]) cnt[1]++;
			if(a[i][2] > a[i][0] && a[i][2] > a[i][1]) cnt[2]++;
//			cout << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << endl;
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) q.push(max(a[i][1], a[i][2]) - a[i][0]);
		}
		while(cnt[0] > n >> 1)
			answer += q.top(), cnt[0]--, q.pop();
		cout << answer << endl;
	}

	return 0;
}
