//SN-J00589 李雨轩 陕西延安中学 
#include <iostream>
using namespace std;
int a[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin >> a[i][j];
		}
	}
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]>a[1][1]) 
			{
				sum++;
			}
		}
	}
	int num_n=1,num_m=1;
	for (int i=1;i<=sum;i++)
	{
		if (num_m%2==1 && num_n+1<=n)
		{
			num_n++;
		}
		else if(num_m%2==0 && num_n-1>=1)
		{
			num_n--;
		}
		else if (num_n+1>n) 
		{
			num_m++;
		}
		else if(num_n-1<1) 
		{
			num_m++;
		}
	}
	cout << num_m << " " << num_n;	
	return 0;
}
