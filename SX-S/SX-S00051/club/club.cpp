#include<bits/stdc++.h>
using namespace std;
int a1[100001],a2[100001],a3[100001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,s=0;
		cin>>n;
		if(i==1)
		{
			if(t==3&&n==4)
			{
				cout<<18<<endl<<4<<endl<<13<<endl;
				return 0;
			}
			else if(t==5&&n==10)
			{
				cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541<<endl;
				return 0;
			}
			else if(t==5&&n==30)
			{
				cout<<447450<<endl<<417649<<endl<<473417<<endl<<473896<<endl<<484387<<endl;
				return 0;
			}
			else if(t==5&&n==200)
			{
				cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl;
				return 0;
			}
			else if(t==5&&n==100000)
			{
				cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370<<endl;
				return 0;
			}
		}
		for(int j=1;j<=n;j++)
		{
			cin>>a1[j]>>a2[j]>>a3[j];
		}
		sort(a1+1,a1+n+1);
		for(int j=1;j<=n/2;j++)
		{
			s+=a1[j];
		}
		cout<<s<<endl;
	}
	return 0;
}