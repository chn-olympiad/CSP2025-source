#include <bits/stdc++.h>
using namespace std;
long long n,m,a[15][15],b[105],cnt,j,k,c,r;
bool cmp(long long x,long long y) 
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> b[i];
	cnt = b[1];
	k = n * m;
	sort(b + 1,b + k + 1,cmp);
	for(int i = 1;i <= k;i++)
	{
		if(b[i] == cnt) j = i;
	}
	if(j % n != 0) c = (j / n) + 1;
	else c = j / n;
	if(c % 2 == 1)
	{
		if(j % n == 0)
		{
			r = n;
		}
		else r = j % n;
	}
	else
	{
		if(j % n == 0)
		{
			r = 1;
		}
		else r = n - (j % n) + 1;
	}
	cout << c << " " << r;
	return 0;
}
