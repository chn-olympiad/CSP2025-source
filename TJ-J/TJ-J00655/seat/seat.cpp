#include "bits/stdc++.h"

#define ll long long

using namespace std;

ll n, m, a[105][105];

struct stu
{
	ll v, l;
}p[1005];

int cmp(stu x, stu y)
{
	return x.v > y.v; 
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(ll i = 1;i <= n*m;i ++)
	{
		cin >> p[i].v;
		p[i].l = i;
	}
	
	sort(p+1,p+(n*m)+1, cmp);
	
	ll flag;
	for(ll i = 1;i <= n*m;i ++)
	{
		
		if(p[i].l == 1) 
		{
			flag = i;
			break;
		}
	}
	

	ll i = 1, j = 1, num = 1;
	while(j <= m)
	{
		
		a[i][j] = num;
		
		if(num == flag)
		{
			cout << j << " " << i;
			break;
		}
		
		num ++;
		if(j % 2 == 1)
		{
			if(i < n) i ++;
			else if(i == n) j ++;
			continue;
		}
		else
		{
			if(i > 1) i --;
			else if(i == 1) j ++;
		}
	}
	
	
	return 0;
}
