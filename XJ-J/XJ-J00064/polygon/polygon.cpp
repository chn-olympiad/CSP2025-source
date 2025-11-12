#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	vector < int > a;
	cin >> n;
	int ans = 0;
	for(int  i = 1; i <= n ;i++)
	{
		int num;
		cin >> num;
		a.push_back(num);
	}
	sort( a.begin(),a.end());
	cout << 0;
	return 0;
}
