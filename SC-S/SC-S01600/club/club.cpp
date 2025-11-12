#include<bits/stdc++.h>
#define F(i,l,r) for(int i(l); i <= (r); ++ i)
#define G(i,r,l) for(int i(r); i >= (l); -- i)
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
using ll = long long;
const int N = 2e5;
struct node{
	int id, pos, val;
	bool operator < (const node &other)const{
		return val > other.val;
	}
}b[N], c[N];
int T, n, a[N][5], r[N], num = 0;
vector<int> cnt[5];
bool cmp(const int &x, const int &y){
	return x > y;
}
namespace task{
	void Main(){
		int sum = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		num = 0;
		cin >> n;
		F(i, 1, n){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int mx = max({a[i][1], a[i][2], a[i][3]});
			sum += mx;
			if(mx == a[i][1]){
				cnt[1].push_back(i);
			}
			else if(mx == a[i][2]){
				cnt[2].push_back(i);
			}
			else{
				cnt[3].push_back(i);
			}
		}
		cnt1 = cnt[1].size();
		cnt2 = cnt[2].size();
		cnt3 = cnt[3].size();
		int delta;
		if(cnt1 > n / 2){
			delta = cnt1 - n / 2;
			for(auto id : cnt[1]){
				r[++ num] = max(a[id][2], a[id][3]) - a[id][1]; 
			}
		}
		else if(cnt2 > n / 2){
			delta = cnt2 - n / 2;
			for(auto id : cnt[2]){
				r[++ num] = max(a[id][1], a[id][3]) - a[id][2]; 
			}
		}
		else{
			delta = cnt3 - n / 2;
			for(auto id : cnt[3]){
				r[++ num] = max(a[id][1], a[id][2]) - a[id][3]; 
			}
		}
		sort(r + 1, r + num + 1, cmp);
//		cout << sum << '\n';
		F(i, 1, delta) sum += r[i];
		cout << sum << '\n';
		F(i, 1, 3) cnt[i].clear();
	}
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while(T --) task::Main();
	return fflush(0), 0;
}