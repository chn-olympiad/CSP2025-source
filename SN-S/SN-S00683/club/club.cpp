#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int like[3][N];
int nums[N];

int lim;
long long res;
long long tot;

void dfs(int r , int n)
{
	if(r == n)
	{
		tot = max(res , tot);
		return;
	}
		
	for(int i = 0 ; i < 3 ; i ++)
	{
		if(nums[i] < lim)
		{
			res += like[i][r];
			nums[i] ++;
			dfs(r + 1 , n);
			res -= like[i][r];
			nums[i] --;
		}
	}
}


int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	cin >> t;
	for(int ouo = 0 ; ouo < t ; ouo ++)
	{
		bool pa = 0;
		bool pb = 0;
		int n;
		cin >> n;
		lim = n / 2;
		for(int i = 0 ; i < n ; i ++)
		{
			cin >> like[0][i] >> like[1][i] >> like[2][i];
			if(like[1][i] != 0) pa = 1;
			if(like[2][i] != 0) pb = 1;
		}
		if(pa == 0)
		{
			sort(like[0] , like[0] + n);
			for(int i = 0 ; i < lim ; i ++) tot += like[0][i];
		}
		else
		{
			dfs(0 , n);
		}
		cout << tot << endl;
		tot = 0;
		res = 0;
	}
}
