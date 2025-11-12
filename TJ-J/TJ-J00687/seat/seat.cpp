#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int b=a[0];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[j]<a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	int c=0,r=0;
	for(int i=1;i<=n;i++)
	{
		c++;
		for(int j=1;j<=m;j++)
		{
			r++;
			if(b==a[i])
			{
				cout<<c<<" "<<r;
				break;
			}
		}
		
	}
	return 0;
}
