#include<bits/stdc++.h>
using namespace std;

int a[105];
int n;
int m;
int c;
int r;
int R;
int seat=1;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	//cout<<R;
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<a[i]<<" "; 
//	}
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++,seat++)
			{
				if(a[seat]==R)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=m;j>=1;j--,seat++)
			{
				if(a[seat]==R)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
} 
