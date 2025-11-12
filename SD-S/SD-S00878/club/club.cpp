#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t>>n;
	int s=0;
	for(int i=1;i<=t;i++)
	{
		int a1[5],b1[5],c1[5];
		for(int j=1;j<=n;j++)
		{
			cin>>a1[j]>>b1[j]>>c1[j];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				
				if(a1[j]>s)
				{
					s=a1[j];
					cout<<s;
				}
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int n[7];
int m[100000];
int q[
int t;
cin>>t;
for(int i=1;i<=t;i++)
{
	cin>>n[i];
	cin>>m[i];
}






