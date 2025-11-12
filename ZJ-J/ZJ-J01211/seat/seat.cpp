#include<bits/stdc++.h>
using namespace std;
long long f,a[1010],c[20][20],n,m,s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m);
	long long cnt=n*m;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				c[j][i]=a[cnt--];
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				c[j][i]=a[cnt--];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(c[j][i]==s)
			{
				cout<<i<<" "<<j;
				f=1;
				break;
			}
		}
		if(f==1)break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}