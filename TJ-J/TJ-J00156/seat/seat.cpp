#include<bits/stdc++.h>
using namespace std;

int n,m,a1;
int a[20*20];

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i*m+j];
			if(i==1&&j==1) a1=a[1];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a1==a[i*m+j])
			{
				if(i%2==0) cout<<i+1<<" "<<j<<endl;
				else cout<<i+1<<" "<<m-j+1<<endl;
				return 0;
			}
		}
	}
	return 0;
}
