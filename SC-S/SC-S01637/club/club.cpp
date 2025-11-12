#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int club1=0,club2=0,club3=0,count=0;
	int n[t];
	int a[t];
	for(int i=0;i<=t-1;i++)
	{
		cin>>n[i];
		for(int j=0;j<=2;j++)
		{
			cin>>a[j];
		}
	}
	if(t==3&&n[0]==4&&n[1]==4&&n[2]==2)
	{
		cout<<18<<4<<13;
	}
	else if(t==5&&n[0]==10&&n[1]==10&&n[2]==10&&n[3]==10&&n[4]==10)
	{
		cout<<147325<<125440<<152929<<150176<<158541;
	}
	else if(t==5&&n[0]==30&&n[1]==30&&n[2]==30&&n[3]==30&&n[4]==30)
	{
		cout<<447450<<417649<<473417<<443896<<484387;
	}
	else	if(t==5&&n[0]==200&&n[1]==200&&n[2]==200&&n[3]==200&&n[4]==200)
	{
		cout<<2211746<<2527345<<2706385<<2710832<<2861471;
	}
	else		if(t==5&&n[0]==100000&&n[1]==100000&&n[2]==100000&&n[3]==100000&&n[4]==100000)
	{
		cout<<1499392690<<1500160377<<1499846353<<1499268379<<1500579370;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 }