#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,ans,a[1000];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i ++)
	{
		cin >> a[i];
	}
	ans = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i ++)
	{
		if(a[i] == ans) 
		{
			if(((i-1)/n)%2 == 0) cout << ((i-1)/n+1) << " " << ((i-1)%n+1);
			else cout << ((i-1)/n+1) << " " << (n-(i-1)%n);
			break;
		}
	}
	return 0;
}