#include <bits/stdc++.h>
using namespace std;
int m[1000005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1 ; i <= t ; i++)
	{
		int n;cin >> n;
		int x,y,ans = 0;
		for(int j = 1 ; j <= n ; j++)
		{
			cin >>m[j] >>x >> y;	
		}
		sort(m+1,m+n+1);	
		for(int j = n ; j > n/2  ; j--)
		{
			ans += m[j];
		}
		cout << ans << endl;
	}
	return 0;
}
