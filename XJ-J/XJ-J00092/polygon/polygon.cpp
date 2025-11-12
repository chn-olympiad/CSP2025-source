#include<bits/stdc++.h>
using namespace std;
long long n, a[50000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(a[1] + a[2] > a[3])	sum++;
	if(a[1] + a[3] > a[2])	sum++;
	if(a[3] + a[2] > a[1])	sum++;
	cout << sum % 998;
	return 0;
} 
