#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int k, ans=1;
	int num=n*m;
	int a[num+5];
	for(int i=1;i<=num;i++)
	{
		cin >> a[i];
		k=a[1];
	}
	int cnt=1;
	for(int j=2;j<=num;j++)
	{
		if(a[j]>a[1])
		{
			ans++;
		}
	}
	int x, y;
	x=ans%n;
	if(x!=0)
	{
		y=ans/n+1;
	}
	else
	{
		y=ans/n;
	}
	if(y%2==0)
	{
		if(x==0)
		{
			cout << y << " " << "1";
		}
		else
		{
			cout << y << " " << m+1-x;
		}
	}
	else
	{
		if(x==0)
		{
			cout << y << " " << n;
		}
		else
		{
			cout << y << " " << x;
		}
	}
	return 0;
}
