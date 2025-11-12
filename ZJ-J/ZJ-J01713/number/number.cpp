#include<bits/stdc++.h>
using namespace std;
const int N  = 1e6 + 10;
int a[N];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	getline(cin, s);
	int k = 0;
	for(int i = 0; i < s.size(); i ++)
	{
		if(isdigit(s[i])) a[++ k] = s[i] - '0';
	}
	sort(a + 1, a + k + 1, greater<int>());
	for(int i = 1; i <= k; i ++) cout << a[i];
	cout << endl;
	return 0;
}
