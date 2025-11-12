#include <bits/stdc++.h>

using namespace std;

bool cmp(const int a, const int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string str;
	cin >> str;
	
	vector <int> vec;
	
	for (int i = 0; i < str.size(); i++) 
		if (isdigit(str[i])) 
			vec.push_back(str[i] - 48);
	
	sort(vec.begin(), vec.end(), cmp);
	
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i];
	
	return 0;
}
