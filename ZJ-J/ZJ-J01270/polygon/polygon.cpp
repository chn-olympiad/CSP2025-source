#include<bits/stdc++.h>
using namespace std;
int cnt,sum = 0,n,a[5007];
void dfs(int x,int y,int k)
{
	if(x > k)
	{
		if(sum>2*a[y])
		{
			cnt++;
			if(cnt == 998244353)
			{
				cnt = 0;
			}
		}
		return ;
	}
	for(int i = y+1;i <= n+x-k;i++)
	{
		sum += i;
		dfs(x+1,i,k);
		sum -= i;
	} 
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 3;i <= n;i++)
	{
		dfs(1,0,i);
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
