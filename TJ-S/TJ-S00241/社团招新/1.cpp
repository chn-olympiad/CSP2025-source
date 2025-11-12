#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,a[101],b[101],c[101],sum[101] = {0},m=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>b[j] && a[j]>c[j])
			{
				sum[j]+=a[j];
			}
			if(b[j]>a[j] && b[j]>c[j])
			{
				sum[j]+=b[j];
			}
			if(c[j]>b[j] && c[j]>a[j])
			{					
				sum[j]+=c[j];
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<sum[i]<<"    ";
	}
	return 0;
} 
