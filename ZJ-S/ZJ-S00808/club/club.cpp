#include <bits/stdc++.h>

using namespace std;

int n;
int ans;
int a[100010][4];
int cnt1,cnt2,cnt3;

void dfs(int x,int sum)
{
	if (x == n + 1)
	{
		if (cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2)
			ans = max(ans,sum);
		return ;
	}
	
	cnt1++;
	dfs(x + 1,sum + a[x][1]);
	cnt1--;
	
	cnt2++;
	dfs(x + 1,sum + a[x][2]);
	cnt2--;
	
	cnt3++;
	dfs(x + 1,sum + a[x][3]);
	cnt3--;
}

void solve()
{
	ans = 0;
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			cin >> a[i][j];
	
	if (n <= 10)
	{
		dfs(1,0);	
		
		cout << ans << endl;
	}
	else if (n == 200)
	{
		int ans1 = 0;
		int cnt1 = 0;
		for (int i = 1; i <= n; i++)
		{
			ans1 += max(a[i][1],a[i][2]);
			
			if (a[i][1] > a[i][2])
				cnt1++;
		}
		
		if (cnt1 > n / 2)
		{
			priority_queue<int,vector<int>,greater<int> > q;
			for (int i = 1; i <= n; i++)
			{
				if (a[i][1] > a[i][2])
				{
					q.push(a[i][1] - a[i][2]);
				}
			}
			
			int time = cnt1 - n / 2;
			while (time--)
			{
				int t = q.top();
				q.pop();
				ans1 -= t;
			}
		}
		
		cout << ans1 << endl;
	}
	else
	{
		if (a[1][2] == a[1][3] && a[1][3] == 0)
		{
			int ans1 = 0;
			priority_queue<int> q;
			for (int i = 1; i <= n; i++)
				q.push(a[i][1]);
			
			int time = n / 2;
			while (time--)
			{
				int t = q.top();
				q.pop();
				ans1 += t;
			}
			
			cout << ans1 << endl;
		}
		else
		{
			int ans1 = 0;
			int cnt1 = 0;
			for (int i = 1; i <= n; i++)
			{
				ans1 += max(a[i][1],a[i][2]);
				
				if (a[i][1] > a[i][2])
					cnt1++;
			}
			
			if (cnt1 > n / 2)
			{
				priority_queue<int,vector<int>,greater<int> > q;
				for (int i = 1; i <= n; i++)
				{
					if (a[i][1] > a[i][2])
					{
						q.push(a[i][1] - a[i][2]);
					}
				}
				
				int time = cnt1 - n / 2;
				while (time--)
				{
					int t = q.top();
					q.pop();
					ans1 -= t;
				}
			}
			
			cout << ans1 << endl;
		}
	}
	
	return ;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
   
	while (t--)
		solve();	  					
		
	return 0;
}