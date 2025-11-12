#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin >> str;
	vector<int> ans;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < str.size(); i++){
		if (str[i] >= '0' && str[i] <= '9'){
			ans.push_back(str[i] - '0');
		}
	}
	sort(ans.rbegin(),ans.rend());
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i];
	}
	return 0;
}
