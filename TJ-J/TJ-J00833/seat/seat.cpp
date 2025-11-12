#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[105] = {};
	for(int i = 1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int temp = a[1];
	
	sort(a,a+n*m+1);
	int a1[105] = {};
	for(int i = n*m;i>=0;i--)
	{
		a1[n*m-i+1] = a[i];
	}
	
	int i2 = 0;
	for(int i = 1;i<=n*m;i++)
	{
		if(a1[i] == temp)
		{
			i2 = i;
		}
	}
	int x = i2%n;
	int y = i2/m;
	if(x>0)
	{
		y++;
	}
	if(y%2 == 1)
	{
		if(x!=0)
			cout<<y<<" "<<n;
		else
		{
			cout<<y<<" "<<n;
		}
	}
	else
	{
		cout<<y<<" "<<n-x;
	}


	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
