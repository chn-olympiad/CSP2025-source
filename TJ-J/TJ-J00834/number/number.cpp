#include <bits/stdc++.h>
using namespace std;

string s;
priority_queue<int> ans;

int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(isdigit(s[i])){
			ans.push(s[i]);
		}
	}
	while(!ans.empty()){
		cout << ans.top() - '0';
		ans.pop();
	}
	return 0;
}

