#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int t;
int ans=0;
int a[N][3];
int work(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	int amax[3];
	int y[3];
	for(int i=1;i<=3;i++)
	{
		amax[i]=0;
		y[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][1]>amax[1])
		{
			amax[1]=a[i][1];
			y[1]=i;
			
		}
		if(a[i][2]>amax[2])
		{
			amax[2]=a[i][2];
			y[2]=i;
		}
		if(a[i][3]>amax[3])
		{
			amax[3]=a[i][3];
			y[3]=i;//amax[p]=a[y[i]][p]
		}
	}
	int maxall=0;
	int minall=2100000000;
	int p,q;
	for(int i=1;i<=3;i++)
	{
		if(amax[i]>maxall)
		{
			maxall=amax[i];
			p=i;
		}
		if(amax[i]<minall)
		{
			minall=amax[i];
			q=i;
		}
	}
	ans+=maxall;

	for(int i=1;i<=3;i++)
	{
		if(amax[p]==a[y[i]][p] && amax[6-(p+q)]==a[y[i]][i])
		{
			continue;
		}
		else
		{
			ans+=amax[6-(p+q)];
			break;
		}
	}
	cout<<ans;
}
int main(){
	cin>>t;
	while(t--)
	{
		work();
	}
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return 0;
}
