#include <bits/stdc++.h>
using namespace std;
long long t,n,a[10001],b[10001],c[10001],cnt,ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			if(b[i] == 0 && c[i] == 0)
			{
				if(a[i+1] > a[i])
				{
					a[i] = a[i+1];
					cnt++;
					ans += a[i];
					if(cnt > n / 2)
					{
						cout << ans << endl;
						continue;
					}
				}
			}
//			if(c[i] == 0)
//			{
//				if(a[i] > b[i])
//				{
//					a[i]
//				}
//			}
//			if(n == 2)
//			{
//				if(a[i] > a[i+1] && b[i] > b[i+1]) cout << a[i] + b[i+1];
//				else if(a[i] < a[i+1] && b[i] > b[i+1]) cout << b[i+1]+a[i];
//				else if(b[i] < b[i+1] && a[i] > a[i+1]) cout << b[i+1]+a[i];
//				else if(a[i] == a[i+1] && b[i+1] > b[i]) cout << a[i] + b[i+1];
//			} 
		}
	}
	return 0;
}
