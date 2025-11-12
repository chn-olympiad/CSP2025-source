#include<bits/stdc++.h>
using namespace std;
long long i,n,t;
long long a[10001][6];
long long b[10001];
long long c[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int s=1;s<=t;s++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				b[i]=a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				b[i]=a[i][2];
			}
			else
			{
				b[i]=a[i][3];
			}
			c[s]+=b[i];
		}
	}
	for(int j=1;j<=t;j++)
	{
		cout<<c[j]<<endl;
	}
	return 0;
 } 
