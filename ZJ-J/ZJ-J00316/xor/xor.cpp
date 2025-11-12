#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n , k;
int a[N] , ans;
void dfs(int sum , int last , int cnt , bool flag)
{
	if(last == n)
	{
		ans = max(ans , cnt);
		return;
	}
	if(cnt + n - last <= ans) return;
	for(int i = last + 1; i <= n; i++)
	{
		if(flag == 0)
		{
			dfs(sum ^ a[i] , i , cnt + 1 , 1);
			dfs(sum , i ,cnt ,  0);
		}
		else if(sum == k)
		{
			dfs(a[i] , i , cnt + 1 , 1);
			dfs(0 , i , cnt , 0);
		}
		else dfs(sum ^ a[i] , i , cnt , 1);
	}
}
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		dfs(a[i] , i , 0 , 0);
	}
	cout << ans;
	return 0;
}