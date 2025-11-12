#include <bits/stdc++.h>
using namespace std;

int a[5005],s[5005],n,cnt=0;




int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort (a+1,a+n+1);
	
	for (int i  = 1; i <= n; i++)
		s[i] = s[i-1]+a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = i+3; j <= n; j++)
		{
			if (s[j]-s[i-1] > 2*a[j])
				cnt++;
		}
	}
	cout << cnt*3;
	return 0;
}
