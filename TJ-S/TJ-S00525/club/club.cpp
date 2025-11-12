#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int n;
	cin>>n;
	for(int z=0;z<n;z++)
	{
		int i,an=0,x1,x2,x3;
		int t=i/2;
		cin>>i;
		struct cl{
			int a1;
			int a2;
			int a3;
		}b[10005];
		for(int k=0;k<i;k++)
		{
			cin>>b[k].a1>>b[k].a2>>b[k].a3;
		}
		for(int k=0;k<=i;k++)
		{
			if(x1>t)
			{
				if(b[k].a2>b[k].a3)
				{
					x2++;
					an=an+b[k].a2;
				}
				else
				{
					x3++;
					an=an+b[k].a3;
				}
			}
			else if(x2>t)
			{
				if(b[k].a1>b[k].a3)
				{
					x1++;
					an=an+b[k].a1;
				}
				else
				{
					x3++;
					an=an+b[k].a3;
				}
			}
			else if(x3>t)
			{
				if(b[k].a1>b[k].a2)
				{
					x1++;
					an=an+b[k].a1;
				}
				else
				{
					x2++;
					an=an+b[k].a2;
				}
				
			}
			else
			{
				if(b[k].a1>b[k].a2&&b[k].a1>b[k].a3)
				{
					x1++;
					an=an+b[k].a1;
				}
				else if(b[k].a2>b[k].a1&&b[k].a2>b[k].a3)
				{
					x2++;
					an=an+b[k].a2;
				}
				else
				{
					x3++;
					an=an+b[k].a3;
				}
			}
		cout<<an;
		}
	}
	return 0;
}
