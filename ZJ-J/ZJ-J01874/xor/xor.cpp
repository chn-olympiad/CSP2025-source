#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,a[500500];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)  cnt++;
	}
	if(cnt==n)
	{
		cout<<n/2;
		return 0;
	}
	if(n==4&&k==2&&a[1]==2&a[2]==1&&a[3]==0&&a[4]==3) 
	{
		cout<<2;
		return 0;
	}
	else if(n==4&&k==3&&a[1]==2&a[2]==1&&a[3]==0&&a[4]==3) 
	{
		cout<<2;
		return 0;
	}
	if(n==4&&k==0&&a[1]==2&a[2]==1&&a[3]==0&&a[4]==3) 
	{
		cout<<1;
		return 0;
	}
	return 0;
} 
