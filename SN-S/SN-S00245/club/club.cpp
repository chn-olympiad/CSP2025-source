//张潇扬  SN-S00245  西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int t,n,c[10000][3],a,s;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		s=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>c[j][1]>>c[j][2]>>c[j][3];
			for(int k=0;k<3;k++)
			{
				if(c[j][k]>c[j][k+1])
				{
					int x;
					x=c[j][k+1];
					c[j][k+1]=c[j][k];
					c[j][k]=x;
				}
			}
			s+=c[j][3];
		}
		cout<<s;
	}
	return 0;
}
