#include <bits/stdc++.h>
using namespace std;
int mess[510][3],js[5],maxn=0;
int does(int n,int step,int sum,int yum)
{
	if(step==n) 
	{
		maxn=max(maxn,sum);
		return 0;
	}
	for(int i=0;i<3-yum;i++)
	{
		if(js[i]>=(n/2)) continue;
		js[i]++;
		does(n,step+1,sum+mess[step][i],yum);
		js[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	bool flag1=1,flag2=1;
	while(T--)
	{
		maxn=0;
		cin>>n;
		for(int i=0;i<n;i++) {
			for(int j=0;j<3;j++) {
				if(mess[i][1]!=0) flag1=0;
				if(mess[i][2]!=0) {flag1=0;flag2=0;}
				cin>>mess[i][j];
			}
		}
		if(flag1)
		{
			int err[100010];
			for(int i=0;i<n;i++) err[i]=mess[i][0];
			sort(err,err+n);
			for(int i=n/2;i<n;i++) maxn+=err[i];
		}
		else 
		{
			int yum=0;
			if(flag2) yum=1;
		 	does(n,0,0,yum);
		}
			
		cout<<maxn<<endl;
	}
	return 0;
}