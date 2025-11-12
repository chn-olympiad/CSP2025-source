#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string s;
vector<int> a;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.length();
	for(int i = 0; i < len; i++) {
		if(s[i] >= '0' && s[i] <= '9') a.push_back(s[i] - '0');
	}
	sort(a.begin(), a.end(), greater<int>());
	for(int x : a) cout << x;
	cout << endl;
	return 0;
}
