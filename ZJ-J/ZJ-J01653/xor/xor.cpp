#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1e6 + 10;

int a[N];
int pre[N];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	for(int i = 1;i <= n;i ++) {
		pre[i] = pre[i - 1] ^ a[i];
	}
	vector<PII> q;
	//for(int i = 1;i <= n;i ++) cout << pre[i] << ' ';
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= i;j ++) {
			int d = pre[i] ^ pre[j - 1];
			//cout << j << ' ' << i << ' ' << d << endl;
			if(d == k) {
				q.push_back({i,j});
			}
		}
	}
	sort(q.begin(),q.end());
	int ans = 1;
	int l = q[0].second,r = q[0].first;
	//cout << l << ' ' << r << endl;
	for(int i = 1;i < q.size();i ++) {
		int tl = q[i].second,tr = q[i].first;
		//cout << tl << ' ' << tr << endl;
		if(tl <= r) continue;
		ans ++;
		r = tr;
	}
	cout << ans << endl;
	return 0;
}
