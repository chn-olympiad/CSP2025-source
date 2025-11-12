#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5000000005],m=0,f=0;
signed main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1+i;j<=n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(max(max(i,j),k)*2==i+j+k)
				{
					f++;
				}
			}
		}
	}
	cout<<f%998;
	return 0;
}

