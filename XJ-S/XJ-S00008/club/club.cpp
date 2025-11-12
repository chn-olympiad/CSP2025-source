#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long int T,n,a[N][5],ans,flag[5],num,lol;
void dfs(int now,int cnt)
{
	long long int c = num;
	if(flag[cnt] == n / 2)
	{
		return;
	}
	num += a[now][cnt];
	flag[cnt]++;
	if(now == n)
	{
		ans = max(num,ans);
		num = c;
		flag[cnt]--;
		return;
	}
	dfs(now + 1,1);
	dfs(now + 1,2);
	dfs(now + 1,3);
	num = c;
	flag[cnt]--;
	lol++;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--)
	{
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				cin >> a[i][j];
			}
		}
		dfs(1,1);
		num = 0;
		flag[1] = 0;
		flag[2] = 0;
		flag[3] = 0;
		dfs(1,2);
		num = 0;
		flag[1] = 0;
		flag[2] = 0;
		flag[3] = 0;
		dfs(1,3);
		num = 0;
		flag[1] = 0;
		flag[2] = 0;
		flag[3] = 0;
		cout << ans << "\n";
	}
	return 0;
}

