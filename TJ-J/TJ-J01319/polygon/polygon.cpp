#include<iostream>
#include<iomanip>
using namespace std;



int main()
{
	freopen("seat.in","r",in)
	freopen("seat.out","w",out)
	int n;
	int m;
	int jntm;
	int dxxk;
	int ngm;
	cin>>n>>m;
	int a[n][m];
	cin>>a[0];
	jntm = a[0];
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=m;j++)
		cin>>a[i][j];
		
	}
	for(int i=1;i<=n+m;i++)
	{
		if(a[i]>a[i+1])
		{
			dxxk=a[i];
			a[i]=a[i+1];
			a[i+1]=dxxk;
		}
	}
	for(int i=1;i<=n+m;i++)
	{
		if(a[i]==jntm)
		{
			cout<<i;
			ngm=i;
			break;
		}
	}
	if(ngm<n)
	{
		cout<<ngm;
	}
	
	
	return 0;
}
