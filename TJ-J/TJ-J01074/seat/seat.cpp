#include <bits/stdc++.h>
using namespace std;
int n,m,s[110],s2[110],k=0,r1,r2,mr;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> s2[0];
	r1 = s2[0];
	for(int i = 1; i < n*m; i++)
	{
		cin >> s2[i];
	}
	sort(s2,s2+n*m);
	for(int j = n*m-1; j >= 0; j--)
	{
		s[k] = s2[j];
		if(s[k] == r1)
		{
			r2 = k+1;
		}
		k++;
	}
	if(r2%n == 0)
	{
		mr = r2 / n;
	}
	else if(r2%n != 0)
	{
		mr = r2 / n + 1;
	}
	cout << mr << " ";
	if(mr % 2 == 1)
	{
		if(r2%n != 0)
		{
			cout << r2%n;
		}
		else if(r2%n == 0)
		{
			cout << n;
		}
	}
	else if(mr % 2 == 0)
	{
		if(r2%n != 0)
		{
			cout << n-r2%n+1;
		}
		else if(r2%n == 0)
		{
			cout << 1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
