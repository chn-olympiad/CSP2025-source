//SN-S00117  吴禹泽  陕西延安中学
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int t, n, spa = 1, spb = 1;
int a1[100005], a2[100005], a3[100005];

bool cmp(int a, int b) {
	return a > b;
}

struct P {
	int id, los;
	bool operator < (P b) const {
		return this->los > b.los;
	}
};

inline void spworka() {
	int ans = 0;
	sort(a1+1, a1+n+1, cmp);
	for(int i=1; i<=n/2; i++) {
		ans += a1[i];
	}
	cout<<ans<<'\n';
	return;
}

inline void spworkb() {
	priority_queue<P> q1, q2;
	int ans = 0, cnt1 = 0, cnt2 = 0;
	for(int i=1; i<=n; i++) {
		if(a1[i] > a2[i]) {
			if(cnt1 < n/2) {
				cnt1 ++;
				ans += a1[i];
				q1.push({i, a1[i] - a2[i]});
			} else {
				if(ans - q1.top().los + a1[i] > ans + a2[i]) {
					int h = q1.top().id;
					ans = ans - q1.top().los + a1[i];
					q1.pop();
					q1.push({i, a1[i] - a2[i]});
					q2.push({h, a2[h] - a1[h]});
				} else {
					q2.push({i, a2[i] - a1[i]});
					ans += a2[i];
				}
			}
		} else if(a1[i] <= a2[i]) {
			if(cnt2 < n/2) {
				cnt2 ++;
				ans += a2[i];
				q2.push({i, a2[i] - a1[i]});
			} else {
				if(ans - q2.top().los + a2[i] > ans + a1[i]) {
					int h = q2.top().id;
					ans = ans - q2.top().los + a2[i];
					q2.pop();
					q2.push({i, a2[i] - a1[i]});
					q1.push({h, a1[h] - a2[h]});
				} else {
					q1.push({i, a1[i] - a2[i]});
					ans += a1[i];
				}
			}
		}
	}
	cout<<ans<<'\n';
	return;
}

int cnt1, cnt2, cnt3, ansans = 0;
void dfs(int k, int v) {
	if(k == n + 1) {
		ansans = max(ansans, v);
		return ;
	}
	
	for(int i=1; i<=3; i++) {
		if(cnt1 < n/2 && i == 1) {
			cnt1 ++;
			dfs(k+1, v + a1[k]);
			cnt1 --;
		} else if (cnt2<n/2 && i == 2) {
			cnt2 ++;
			dfs(k+1, v + a2[k]);
			cnt2 --;
		} else if(cnt3<n/2 && i==3) {
			cnt3 ++;
			dfs(k+1, v + a3[k]);
			cnt3 --;
		}
	}
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	fastio;

	cin>>t;
	while(t --) {
		spa = 1, spb = 1, ansans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		memset(a1, 0, sizeof(a1));
		memset(a2, 0, sizeof(a2));
		memset(a3, 0, sizeof(a3));
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i] || a3[i]) spa = 0;
			if(a3[i]) spb = 0;
		}
		if(spa) {
			spworka();
			continue;
		} else if(spb) {
			spworkb();
			continue;
		} else {
			dfs(1, 0);
			cout<<ansans<<'\n';
		}
	}
	return 0;
}
