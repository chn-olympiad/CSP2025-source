#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n=0,m=0,a1=0,s=0,b=0,c=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	a1=a[0];
	for(int i=0;i<n*m;i++)
	{
		for(int j=0;j<n*m;j++)
		{
			if(a[j]<a[j+1])
			{
				n=a[j];
				a[j]=a[j+1];
				a[j+1]=n;
			}
		}
	}
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==a1)
		{
			b=i+1;
			break;
		}
	}
	if(b%m==0)
	{
		c=b/m+m-1;
		cout<<c<<" ";
	}
	if(c%2!=0)
	{
		if(b%m!=0)
		{
			cout<<b%m;
		}
		else
		{
			cout<<m;
		}
	}
	else
	{
		cout<<m-b%m+1;
	}
	return 0;
}
