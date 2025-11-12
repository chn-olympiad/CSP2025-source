#include <iostream>
#include <algorithm>
using namespace std;
int n,k;
long long a[5000005][5000005],b[5000005];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			a[i][j]=a[i][j-1]^b[j];
		}
	}
	int cnt=0;
	int l=1,r=1;
	while(r<=n)
	{
		if(r==n&&l<n)
		{
			l++;
			r=l;
		}
		if(a[l][r]==k)
		{
			cnt++;
			r++;
			l=r+1;
		}
		else
		{
			
			r++;
		}
		
	}
	cout<<cnt;
	return 0;
 } 
