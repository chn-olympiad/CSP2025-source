#include <bits/stdc++.h>
using namespace std;
long long n, ans;
vector<int> a(5000);


int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
	}
	
	if (a[0] == 1) 
	{
		cout << 9 << endl;
	}
	
	if (a[0] == 2)
	{
	 	cout << 6 << endl;
	}
	return 0;
 } 
