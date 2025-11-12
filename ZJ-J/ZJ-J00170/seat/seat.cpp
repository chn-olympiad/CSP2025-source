#include<bits/stdc++.h>
using namespace std;

int n, m;
int a1;
vector<int> nums;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n*m;i++) {
		int _;
		cin >> _;
		if(i == 0){
			a1 = _;
		}
		nums.push_back(_);
	}
	sort(nums.rbegin(), nums.rend());
	vector<vector<int> > ans(n+5, vector<int> (m+5));
	int cnt = 0;
	for(int j = 1; j <= m; j++) {
		if(j%2 == 1){
			for(int i = 1; i <= n; i++){
				ans[i][j] = nums[cnt];
				cnt++;
			}
		}else {
			for(int i = n; i >= 1; i--){
				ans[i][j] = nums[cnt];
				cnt++;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++){
			if(ans[i][j] == a1) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
}
