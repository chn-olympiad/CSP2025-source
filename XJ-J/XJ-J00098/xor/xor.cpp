#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	int n,k,l,r,s=0,sum=0,bb;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(l=1;l<=n;l++)
	{
		for(r=l+1;r<=n;r++)
		{
			bb=r-l;
			int j=l;
			s=a[j];
			while(bb--)
			{
				s+=s xor a[j+1];
				j++;
			}
			if(k==s)
			{
				sum++;
				
			}
		}
	}
	cout<<sum;
	return 0;
} 
