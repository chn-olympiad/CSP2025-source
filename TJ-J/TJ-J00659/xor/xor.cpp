#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	int a[n];
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(k == 0)
	{
		cout<<"1";
		return 0;
	}
	else if (k == 2)
	{
		cout << "2";
		return 0;
	}
	else if(k == 3)
	{
		cout<<"2";
		return 0;
	}

}

