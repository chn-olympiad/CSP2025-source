#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[501];
int ans = 0,cnt = 0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s = '0' + s;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	queue<int> q;
	for(int i = 1;i <= n; i++)
	{
		cnt = 0;
		for(int k = i; k <= n; k++)
		{
			q.push(a[k]);
		}
		for(int k = 1; k <= i; k++)
		{
			q.push(a[k]);
		}
		for(int k = 1; k <= n; k++)
		{
			int x = q.front();
			q.pop();
			if(a[i] == 1)
			{
				cnt++;	
			}
		}
		if(cnt >= m)
		{
			ans++;
		}	
	}
	cout << ans << endl;
	fclose(0);
	return 0;
}
