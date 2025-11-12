#include <bits/stdc++.h>

using namespace std;
int n,ans;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int a=0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a;
	}
	for(int i = 1;i <= n-n%3;i++)
	{
		ans+=i;
	}
	cout << ans%998%244%353;
	return 0;
}
