#include<bits/stdc++.h>
using namespace std;

namespace z {
#define int long long 
const int N = 1e5 + 5;
int a[N][3], c[3];
void solve() {
	c[0] = c[1] = c[2] = 0;
	int n; cin >> n;
	vector<int> A, B, C;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++)
			cin >> a[i][j];
		int mx = max({a[i][0], a[i][1], a[i][2]});
		if(a[i][0] == mx) A.push_back(i), c[0]++;
		else if(a[i][1] == mx) B.push_back(i), c[1]++;
		else C.push_back(i), c[2]++;
		ans += mx;
	}
	if(A.size() <= n / 2 &&B.size()<=n/2&&C.size()<=n/2)cout<<ans<<'\n';
	else {
		vector<int> t;
		if(A.size()>n/2){
			for(int i : A) 
				t.push_back(max(a[i][1]-a[i][0],a[i][2]-a[i][0]));
			sort(t.begin(), t.end(), greater<int>());
			for(int i = 0; i < A.size()-n/2;i++)ans+=t[i];
		}
		if(B.size()>n/2){
			for(int i : B) 
				t.push_back(max(a[i][0]-a[i][1],a[i][2]-a[i][1]));
			sort(t.begin(), t.end(), greater<int>());
			for(int i = 0; i < B.size()-n/2;i++)ans+=t[i];
		}
		if(C.size()>n/2){
			for(int i : C) 
				t.push_back(max(a[i][0]-a[i][2],a[i][1]-a[i][2]));
			sort(t.begin(), t.end(), greater<int>());
			for(int i = 0; i < C.size()-n/2;i++)ans+=t[i];
		}
		cout<<ans<<'\n';
		
	}
	
}
void main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) solve();
}
#undef int
} 

int main() {
	z::main();
	return 0;
}
