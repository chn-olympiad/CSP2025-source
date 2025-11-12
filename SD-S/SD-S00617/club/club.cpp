#include <bits/stdc++.h>
using namespace std;
int t,n;
int ans = 0;
const int maxn = 2e5 + 5;
int a[maxn],b[maxn],c[maxn];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a + 1,a+1+n);
		sort(b + 1,b+1+n);
		sort(c + 1,c+1+n);
		for(int j = n;j >= n/2+1;j--)
		  {
			ans += a[j] + b[j] + c[j];
		  }
	}
	cout << ans << endl;
	return 0;
}

