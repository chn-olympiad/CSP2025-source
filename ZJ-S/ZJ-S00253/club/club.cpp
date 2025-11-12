#include<bits/stdc++.h>
using namespace std; 
long long n,vm=-1,k;
long long a[100003][5],l[5];
long long dp(long long x,long long v)
{
	if(x==n+1)
	{
		vm=max(vm,v);
		return v;
	}
	else
	{
		long long vmax=-1;
		for(long long i=1;i<=3;i++)
		{
			if(l[i]!=n/2)
			{
				l[i]++;
					vmax=max(vmax,dp(x+1,v+a[x][i]));
				l[i]--;
			}
		}
		return vmax;
	}

}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
 	long long t;
 	cin>>t;
 	while(t--)
 	{
 		cin>>n;
 		for(long long i=1;i<=n;i++)
 			cin>>a[i][1]>>a[i][2]>>a[i][3];
 		dp(1,0);
 		cout<<vm<<endl;
 		vm=-1;
	}
	return 0;
}
/*                                                                                               我也要写小作文，但我天生就是魔丸，是命中注定！食蘑食蚬，我自己说了不算*/ 
