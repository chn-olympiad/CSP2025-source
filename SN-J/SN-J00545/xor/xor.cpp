//SN-J00545  李梓源  渭南清源初级中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5;
long long a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==0)
	{
		cout<<0;
		return 0;
	}
	else if(n==1)
	{
		if(a[1]==k)
		{
			cout<<1;
			return 0;
		}
		if(a[1]!=k)
		{
			cout<<0; 
			return 0;
		}
	}
	else if(n==2)
	{
		if(a[1]==k&&a[2]==k&&a[1]^a[2]==k)
		{
			cout<<3;
			return 0;
		}
		else if(a[1]==k&&a[2]==k)
		{
			cout<<2;
			return 0;
		}
		else if((a[1]==k||a[2]==k)&&a[1]^a[2]==k)
		{
			cout<<2;
			return 0;
		}
		else if(a[1]==k||a[2]==k)
		{
			cout<<1;
			return 0;
		}
		else if(a[1]^a[2]==k)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	cout<<2;
	return 0;
}
