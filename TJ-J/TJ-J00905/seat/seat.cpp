#include <bits/stdc++.h> 
using namespace std;

long long m,n,a[9999],al,ans; 

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i< n*m;i++)
	{
		cin >> a[i];
		if(i == 0)
		{
			al=a[i];
		}
	}
	sort(a,a+(m*n));
	for(int i = n*m-1;i>= 0;i--)
	{
		if(a[i] == al)
		{
			ans = m*n-i;
			break;
		}
	}
	int ml = ans / n,nl = ans%n;
	if((ans%n)>0)
	{
		ml++;
	}
	cout << ml << ' ';
	if(ml  % 2)
	{
		if(ans% n == 0)
		{
			cout << n;
			return 0;
		}
		cout << nl;
	}
	else
	{
		cout << n - nl;
	}
	fclose(stdin); 
	fclose(stdout); 
	return 0;
}
