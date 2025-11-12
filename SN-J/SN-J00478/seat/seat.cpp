#include<bits/stdc++.h>
using namespace std;
int cmp(int x , int y )
{
	if(x < y)
	return x > y;
}
int l[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n ,m ,a[10001];
	
	cin >> n >> m;
	for(int i = 1  ; i <= n * m ; i++)
	{
		cin >> a[i];
	}
	int c = a[1] , b;
	sort(a+1,a+n*m+1,cmp);
	int o=1,p=1;
	for(int i = 1 ; i <= n * m ; i++)
	{
		l[o][p] = a[i];
		if(l[o][p] == c)
		{
			cout << p << " " << o ;
			cout << endl;
		}
		if(p%2 != 0)
		{
			if(o + 1 <= n)
			{
				o++;
			}
			
			else if(o + 1 > n)
			{
				p++;
			}
		}
		else if(p%2 == 0)
		{
			if(o - 1 > 0)
			{
				o--;
			}
			
			else if(o - 1 <= 0)
			{
				p++;
			}
		}
	}

	return 0;
}
