#include<bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
vector<int> nums;
vector<int> two(n+5);
int find(int L, int R, int num) {
	int l = L,r = R;
	if(l == r) return l-1;
	while(l < r) {
		int mid = (l+r)/2;
		if(nums[mid] > num) {
			r = mid-1;
		}else if(nums[mid] < num) {
			l = mid+1;
		}else {
			return mid-1;
		}
	}
	if(nums[l] == num) return l-1;
	return l;
}
void dfs(int l, int r, int sum, int f) {
	if(f == 1) {
		int pos = find(r+1,n,sum);
	//	if(l == 1 && r == 3) cout << "aaa" << " " << pos <<" " << sum << endl;
		ans += pos-r;
		
//		cout <<l << " " << r << " " << pos << " "<<  sum << " " << ans << endl;
		if(r < n) {
			dfs(l,r+1,sum + nums[r+1], 1);
			dfs(l,r+1,sum, 0);
		}
	}else {
		if(r < n){
			dfs(l,r+1,sum + nums[r+1], 1);
			dfs(l,r+1,sum, 0);
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	nums.push_back(0);
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		nums.push_back(a);
	}
	sort(nums.begin(), nums.end());
	for(int i = 1; i <= n; i++) two[i] = nums[i]*2;
	for(int i = 1; i <= n; i++){
		dfs(i,i+1,nums[i]+nums[i+1], 1);
//			cout << ans << endl;
	}
	cout << ans;
}
