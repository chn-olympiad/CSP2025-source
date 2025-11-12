#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],k,b[1005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m,cmp);
	if(a[1]==r)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	int dl=1,dh=1;
	for(int i=2;i<=n*m;i++)
	{
		
		if(dl%2==1)
		{
			if(dh<n)
			{
				dh++;
			}
			else if(dh==n)
			{
				dl++;
				dh=n;
			}
		}
		else if(dl%2==0)
		{
			if(dh>1)
			{
				dh--;
			}
			else if(dh==1)
			{
				dl++;
				dh=1;
			}
		}
		if(a[i]==r) 
		{
			cout<<dl<<" "<<dh;
			return 0;
		}
	}
	return 0;
}

