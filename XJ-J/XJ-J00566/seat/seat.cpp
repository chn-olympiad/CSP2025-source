#include<bits/stdc++.h>
using namespace std;
int a[20],b[110][110];
int main()
{

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++)
	{
		cin>>a[i];
	} 
	sort(a,a+len+1);
	int x=0;
	for(int i=1;i<=n;i++)
	{
		b[i][1]=a[i];
		x++;
	}
	for(int i=1;i<=n;i++)
	{
		b[i][2]=a[i+2];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<b[i][j]<<" ";
		}
	cout<<endl;
	}
	
	return 0;
}

