#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		if('0' <= s[i] and s[i] <= '9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(), a.end(), [](int x, int y) {
		return x > y;
	});
	for(int i: a) cout << i; 
	return 0;
} 
