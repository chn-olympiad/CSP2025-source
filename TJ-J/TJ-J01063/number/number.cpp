#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> a;
	string str;
	cin >> str;
	int count = 0;
	for (int i = 0;i < str.size();i++) {
		if (str[i] - '0' < 10 && str[i] - '0' >= 0) {
			a.push_back(str[i] - '0');
			count += 1;
		}
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0;i < count;i++) {
		cout << a[i];
	}
	return 0;
}
