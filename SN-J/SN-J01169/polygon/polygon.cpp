//SN-J01169 马歆玥 西安滨河学校 
#include <bits/stdc++.h>
using namespace std;
int n,sum,maxn,num1;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		sum += a[i];
		maxn = max(a[i],maxn);
		if(a[i] == 1)
			num1++; 
	}
	if(sum <= maxn * 2)
	{
		cout << 0;
		return 0;
	}
	if(n == 3)
	{
		cout << 1;
		return 0;
	}
	if(num1 == n)
	{
		cout << n-2;
		return 0;
	}
	cout << 0;
	return 0;
}
