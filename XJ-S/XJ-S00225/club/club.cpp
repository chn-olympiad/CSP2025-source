#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a1[N],a2[N],a3[N],b1[N],b2[N],b3[N],btm[10];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n;
		int x1=0,x2=0,x3=0,atm=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>=a2[i]&&a1[i]>=a3[i])
			{
				x1++;
				atm+=a1[i];
				b1[x1]=max(a2[i]-a1[i],a3[i]-a1[i]);
			}
			else if(a2[i]>=a1[i]&&a2[i]>=a3[i])
			{
				x2++;
				atm+=a2[i];
				b2[x2]=max(a1[i]-a2[i],a3[i]-a2[i]);
			}
			else if(a3[i]>=a1[i]&&a3[i]>=a2[i])
			{
				x3++;
				atm+=a3[i];
				b3[x3]=max(a2[i]-a3[i],a1[i]-a3[i]);
			}
		}
		if(x1>n/2)
		{
			sort(b1+1,b1+x1+1,cmp);
			for(int i=1;i<=x1-n/2;i++)
			{
				atm+=b1[i];
			}
		}
		else if(x2>n/2)
		{
			sort(b2+1,b2+x2+1,cmp);
			for(int i=1;i<=x2-n/2;i++)
			{
				atm+=b2[i];
			}
		}
		else if(x3>n/2)
		{
			sort(b3+1,b3+x3+1,cmp);
			for(int i=1;i<=x3-n/2;i++)
			{
				atm+=b3[i];
			}
		}
		btm[j]=atm;
	}
	for(int i=1;i<=t;i++)
	{
		cout<<btm[i]<<endl;
	}
	return 0;
}
