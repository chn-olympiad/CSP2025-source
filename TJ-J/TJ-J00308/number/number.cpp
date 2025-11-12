#include <bits/stdc++.h>

using namespace std;

const int N = 100009;
string s;
int nums[N], size = 0;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0;i < s.length();i++){
		if (s[i] <= '9' && s[i] >= '0'){
			nums[size++] = s[i] - '0';
		}
	}
	sort(nums, nums+size);
	for (int i = size-1;i >= 0;i--) cout << nums[i];
	return 0;
}
