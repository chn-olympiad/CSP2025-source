#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long k=n*m;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		if(i==1) x=a[i];
	}
	sort(a+1,a+k+1);
	long long i=1,j=1,f=0;
	for(int l=k;l>=1;l--)
	{
		if(a[l]==x)
		{
			cout<<i<<" "<<j;
			return 0;
		}
		if(f==0&&j==n) i++,f=1;
		else if(f==1&&j==1) i++,f=0;
		else if(f==0) j++;
		else if(f==1) j--;
	}
	return 0;
}