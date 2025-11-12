#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	int z=n/2;
	cin>>t;
	for(int h=0;h<t;h++)
	{
		cin>>n;
		int cnt=0;
		int m=0;
		int  a[n+10],b[n+10],c[n+10];
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			sort (a,a);
			
		}		
	
	for (int j=n;j>z;j--)
	{
		cnt+=a[j];
	}
	cout<<cnt<<endl;
}

	return 0;
 } 
