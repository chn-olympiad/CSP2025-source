#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[200];
	int n,m,r,i,j,w,x=1,flag=0;
	cin>>n>>m;
	r=n*m;
	for(i=1;i<=r;i++)
	{
		cin>>a[i];
	}
	w=a[1];
	sort(a+1,a+r+1,cmp);
	for(j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(i=1;i<=n;i++)
			{
				if(a[x]==w)
				{
					cout<<j<<" "<<i;
					flag=1;
					break;
				}
				x++;
			} 
		}
		if(j%2==0)
		{
			for(i=n;i>=1;i--)
			{
				if(a[x]==w)
				{
					cout<<j<<" "<<i;
					flag=1;
					break;
				}
				x++;
			}
		}
		if(flag==1)
		{
			break;
		}
	}
	return 0;
} 
