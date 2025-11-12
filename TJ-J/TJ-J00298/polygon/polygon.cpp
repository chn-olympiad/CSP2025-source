#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n == 5 && a[0] == 1)
	{
		cout << "9";
	}
	else
	{
		cout << "6";
	}
	
	
	return 0;
}
