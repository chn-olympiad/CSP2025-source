#include<bits/stdc++.h>
using namespace std;
int flag1=0,flag2=0; 
int cmp(int x,int y)
	return x>y;
int main()
{
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	int t,n,a1[10005],a2[10005],a3[10005],sum=0;
	cin>>t;
	for(int t1=1;t1<=t;t1++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]!=0||a3[i]!=0)
				flag1=1;
			if(a3[i]!=0)
				flag2=1;
		}
		if(flag1!)
		{
			sort(a1+1,a1+1+n,cmp);
			for(int i=1;i<=n/2;i++)
				sum+=a[i];
		}
		cout<<sum;
	}
	return 0;
}

