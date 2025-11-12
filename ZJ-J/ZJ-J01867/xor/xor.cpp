#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000001],b[1000001],d;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	b[0]=0;
	cin>>a[0];
	b[1]=a[0];
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
		b[i+1]=a[i]^b[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(int(b[j]^b[i])==k)
			{
				d++;
				cout<<i<<" "<<j<<endl;
				i=j;
				
				break;
			}
		}
	}
	cout<<d;
	return 0;
 }
