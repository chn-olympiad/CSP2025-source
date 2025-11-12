#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200],s,id,nn,mm,a1;
int cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	s = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++)
	{
		if(nn == n+1)
		{
			nn = n;
			mm++;
			a1 = 0;
		}
		if(nn == 0)
		{
			nn = 1;
			mm++;
			a1 = 1;
		}
		if(s == a[i])
		{
			cout << mm << " " << nn;
			break;
		}
		if(a1 == 1)
			nn++;
		else
			nn--;	
	}
	return 0;
}
