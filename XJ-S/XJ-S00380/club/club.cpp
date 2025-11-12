#include<bits/stdc++.h>
using namespace std;
int n;
int maxn=0,maxm=0;
int f1=0,f2=0,f3=0;
int num=0;
int cconut(int a1,int a2,int a3)
{
	if(maxn==a1)
	{
		if(n/2>f1)
		{
			f1++;
			num+=maxn;
		}
	}
	else if(maxn==a2)
	{
		if(n/2>f2)
		{
			f2++;
			num+=maxn;
		}
	}
	else if(maxn==a3)
	{
		if(n/2>f3)
		{
			f3++;
			num+=maxn;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		num=0;
		maxn=0,maxm=0;
		int a1,a2,a3;
		f1=0,f2=0,f3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1>>a2>>a3;
			if(a1=='0' || a2=='0' || a3=='0')
			{
				return 0;
			}
			maxm=max(a2,a3);
			maxn=max(a1,maxm);
			cconut(a1,a2,a3);
		}
		cout<<num<<endl;
	}
	return 0;
 } 
