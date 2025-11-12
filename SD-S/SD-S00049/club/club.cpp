#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int t,n;
int a[maxn][5],b[maxn],c[maxn];
bool cmp(int a,int b)
{
	return a > b;
}
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
			for(int j = 1;j <= 3;j++)
			{
				cin >> a[i][j];
				b[i] = max(a[i][1],b[i]);
				c[i] = max(a[i][2],c[i]);
			}
			
		}
		
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		int ans = 0,cnt = 0;
		
		int s = 0;
		for(int i = 1;i <= n / 2;i++)
			{
				s += b[i];
			}
			cout << s << endl;
		
		
		
	
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				a[i][j] = 0;
				b[i] = 0;
			}
		}
	}
	return 0;
}
