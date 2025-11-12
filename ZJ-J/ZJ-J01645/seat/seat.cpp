#include<bits/stdc++.h>
using namespace std;
bool cmd(int a,int b)
{
	return a>b;
}
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int v=a[1];
	sort(a+1,a+n*m+1,cmd);
	int cnt=0;
	for(int i=1;i<=n*m;i++)
	{
		if((i-1)%n==0)
		{
			cnt++;
		}
		int l;
		if(i%n==0)
		{
			l=n;
		}
		else
		{
			l=i%n;
		}
		if(cnt%2==0)
		{
			if(a[i]==v)
			{
				cout<<cnt<<" "<<n*cnt-i+1;
				break;
			}
		}
		else
		{
			if(a[i]==v)
			{
				cout<<cnt<<" "<<l;
				break;
			}
		}
	}
}
