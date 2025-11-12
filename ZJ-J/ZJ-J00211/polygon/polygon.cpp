#include<bits/stdc++.h>
using namespace std;
int t=0,n=0;
int a[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int s=0,z=0,m=0;
	for(int i=0;i<n;i++)
	{
		z=a[i];
		for(int j=i+1;j<n;j++)
		{
			z+=a[j];
			m=max(a[i],a[j]);
			for(int k=j+1;k<n;k++)
			{
				z+=a[k];
				m=max(m,a[k]);
				if(z>2*m)
				{
					s++;
				}
			}
		}
	}
	cout<<s%998%244%353<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
 } 
