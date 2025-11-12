#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];
	cin >> n >> m;
	int t[110];
	int c,r;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> t[i];
		a[i] = max(t[i],t[i-1]);
	}
	for(int i = 1;i <= n*m;i++)
	{
		while(t[1] == a[i])
		{
			if(i <= n)
			{
				c = i;
				r = 1;
			}
			else 
			{
				c = i-n;
				r = i-m;
			}
		}
		
	}
	
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
