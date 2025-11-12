#include <iostream>
using namespace std;
int main()
{
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	int n,m,b,cnt=1;
	cin>>n>>m;
	int a[m*n];
	for (int i=1;i<=m*n;i++)
	{
		cin>>a[i];
		if(i==1) b=a[i];
	}
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]>b)
		{
			cnt++;
		}
	}
	
	if(cnt<=n)
	{
		cout<<1<<' '<<cnt;
	}
	else
	{
		if(cnt/n%2==1)
		{
			cout<<cnt/n+1<<' '<<n-cnt%n%2+1;
		}
		else
		{
			cout<<cnt/n+1<<' '<<cnt%n%2;
		}
	}
	
	return 0;
}
