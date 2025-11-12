#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 8;
int t;
struct node{
	int val, loc;
};
node a[maxn], b[maxn], c[maxn];
bool cmp(node x,node y){
	return x.val > y.val;
}
int cnt[maxn], sum;
bool inq[maxn][3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		int n; cin >> n; sum = 0;
		memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c)); memset(cnt, 0, sizeof(cnt));
		memset(inq, false, sizeof(inq));
		for (int i = 1;i <= n; i++){
			cin >> a[i].val >> b[i].val >> c[i].val;
			a[i].loc = b[i].loc = c[i].loc = i;
		}
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp);
		sort(c + 1, c + n + 1, cmp);
		for (int i = 1;i <= n/2; i++){
			sum += (a[i].val + b[i].val + c[i].val);
			cnt[a[i].loc]++; cnt[b[i].loc]++; cnt[c[i].loc]++;
			inq[a[i].loc][0] = true; inq[b[i].loc][1] = true;
			inq[c[i].loc][2] = true;
		}
		for (int i = 1;i <= n; i++){
			if (cnt[i] > 1){
				int x = a[i].val, y = b[i].val, z = c[i].val;
				if(cnt[i] == 3){
					if(x > y) swap(x, y);
					if(y > z) swap(y, z);
					if(x > z) swap(x, z);
					sum -= (x + y);
				}
				if(cnt[i] == 2){
					if(inq[i][0] && inq[i][1]){
						sum -= min(x, y);
					}
					else if(inq[i][0] && inq[i][2]){
						sum -= min(x, z);
					}
					else if(inq[i][1] && inq[i][2]){
						sum -= min(y, z);
					}
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}