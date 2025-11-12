#include<bits/stdc++.h>
using namespace std;
struct node {
	int ans, l;
};
int n,k;
vector<vector<int> > mp(50005);
bool find(vector<int> a, int num) {
	int l = 0, r = a.size();
	while(l < r) {
		int mid = (l+r)/ 2;
		if(a[mid] > num) {
			r = mid-1;
		}else if(a[mid] < num) {
			l = mid+1;
		}else {
			return true;
		}
	}
	return false;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	vector<int> nums(n+1);
	for(int i = 1; i <= n; i++) cin >> nums[i];
	if(n == 1) {
		if(nums[1] == k) cout << 1;
		else cout << 0;
	}else if(n == 2) {
		if((nums[1]^nums[2]) == k) cout << 1;
		else if(nums[1] == k || nums[2] == k) cout << 1;
		else cout << 0;
	}else if(k == 0){
		int ans = 0;
		for(int i = 1; i <= nums[i]; i++) {
			if(nums[i] == 0) {
				ans++;
			}
		}
		cout << ans;
	}else {
		for(int i = 1; i <= n; i++) {
		mp[i].push_back(-1);
		int num = 0;
		for(int j = i; j <= n; j++){
			num ^= nums[j];
			if(nums[i] == k) mp[i].push_back(j);
		}
		mp[i].push_back(INT_MAX);
		mp[i].push_back(INT_MAX);
		mp[i].push_back(INT_MAX);
	}
	vector<node> dp(n+5);
	dp[0] = {0,1};
	for(int i = 1; i <= n; i++) {
		if(find(mp[dp[i-1].l], i) || (nums[i] == k)) {
			dp[i].ans = dp[i-1].ans+1;
			cout << dp[i].ans;
			dp[i].l = i+1;
		}
		else dp[i] = dp[i-1];
	}
	cout << dp[n].ans;
	}
	cout << 0;
	
}
