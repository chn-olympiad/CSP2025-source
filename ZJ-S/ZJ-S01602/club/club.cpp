#include <bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005],maxa,maxb,maxc;
int ans;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;
	while(T--)
	{
		ans = 0;
		cin >> n;
		bool flagq = 0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] != 0 || c[i]!=0) flagq = 1;
		}
		if (!flagq)
		{
			sort(a+1,a+n+1);
			for(int i=(n/2+1);i<=n;i++)
			{
				ans+=a[i];
			}
			cout << ans << '\n';
			continue;
		}
		if (n==2)
		{
			for(int i=1;i<n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if (j==1)
					{
						ans = max(ans, a[i]+b[i+1]);
						ans = max(ans, a[i]+c[i+1]);
					}
					if (j==2)
					{
						ans = max(ans, b[i]+a[i+1]);
						ans = max(ans, b[i]+c[i+1]);
					}
					else
					{
						ans = max(ans,c[i]+a[i+1]);
						ans = max(ans,c[i]+b[i+1]);
					}
				}
			}
			cout << ans << '\n';
		}
		else
		{
			for(int i=1;i<n;i++)
			{
				int cnta = 0,cntb = 0,cntc = 0;
				for(int j=1;j<=3;j++)
				{
					for(int dep = 1;dep<n;dep++)
					{
						if (j==1)
						{
							ans = max(ans,a[i] + a[dep+i]);//!
							ans = max(ans, a[i]+b[dep+i]);
							ans = max(ans, a[i]+c[dep+i]);
						}
						if (j==2)
						{
							ans = max(ans,b[i] + b[dep+i]);//!
							ans = max(ans, b[i]+a[dep+i]);
							ans = max(ans, b[i]+c[dep+i]);
						}
						else
						{
							ans = max(ans,c[i] + c[dep+i]);//!
							ans = max(ans,c[i]+a[dep+i]);
							ans = max(ans,c[i]+b[dep+i]);
						}
					}
					
				}
			
				
			}
			cout << ans << '\n';
		}
	}
}
