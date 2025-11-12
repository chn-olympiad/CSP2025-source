#include<bits/stdc++.h>
using namespace std;
long long n,k;
int a[50001];
int yihuo(int x,int y)
{
	if(x%2==y%2)
	{
		if(x>y)
		{
			return x-y;
		}
		else
		{
			return y-x;
		}
	}
	else
	{
		return x+y;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int s=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(k==a[i]&&(i==1||i==n))
		{
			s=2;
		}
	}
	cout<<s;
	return 0;
 } 
