#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int a0;
int a[1024];
bool cmp(int p,int q){
	return p>q;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=m*n;
	for(int i=1;i<=p;i++)cin>>a[i];
	a0=a[1];
	sort(a+1,a+p+1,cmp);
	int num;
	for(int i=1;i<=p;i++)
	{
		if(a[i]==a0)
		{
			num=i;
			break;
		}
	}
	int cnt=0;
	for(int i=1;i<=m;i++)//lie
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				cnt++;
				if(cnt==num)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>0;j--)
			{
				cnt++;
				if(cnt==num)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
