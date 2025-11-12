#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],b[1005][1005];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>m>>n;
	int i,j;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int needs=a[1];
	sort(a+1,a+1+n*m,cmp);
	i=1,j=1;
	int flag=0;
	int cnt=0;
	while(j<=m)
	{
		b[i][j]=a[++cnt];
		if(flag==0)
		{
			if(i+1<=n)
			{
				i++;
			}
			else
			{
				j++;
				flag=1;
			}
		}
		else
		{
			if(i-1>=1)
			{
				i--;
			}
			else
			{
				j++;
				flag=0;
			}
		}
	}
	flag=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(b[i][j]==needs)
			{
				cout<<j<<' '<<i;
				flag=1;
				break;
			}
		}
		if(flag==1)break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

