#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin >> n >> m;
	int a[110],hang,paiming,lie;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i]; 
	}
	int chenji = a[1];
	sort(a+1,a+1+n*m);
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i] == chenji)
		{
			paiming = i;
			break;
		}
	}
	paiming = m*n - paiming + 1;
	if(paiming % n == 0)
		lie = paiming / n;
	else
		lie = paiming / n + 1;
	if(lie % 2 == 0)
	{
		hang =paiming - n * (lie - 1) + 1;
	}
	else hang = paiming - n * (lie - 1);
	cout << lie << " " << hang;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
