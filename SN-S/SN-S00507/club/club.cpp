#include<bits/stdc++.h>
using namespace std;
long long sum;
int T,n,x,y,z,s1,s2,s3,z1[100005],z2[100005],z3[100005],cu,cc;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T ;
	for(int cs=1;cs<=T;cs++)
	{
		s1=0,s2=0,s3=0,sum=0;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> x >> y >> z ;
			if(x>=y&&x>=z)
			{
				sum+=x,s1++;
				if(y>z) z1[s1]=x-y;
				else z1[s1]=x-z;
				continue;
			}
			if(y>=x&&y>=z)
			{
				sum+=y,s2++;
				if(x>z) z2[s2]=y-x;
				else z2[s2]=y-z;
				continue;
			}
			if(z>=x&&z>=y)
			{
				sum+=z,s3++;
				if(x>y) z3[s3]=z-x;
				else z3[s3]=z-y;
				continue;
			}
		}
		cu=n/2;
		if(s1>cu)
		{
			cc=s1-cu;
			sort(z1+1,z1+s1+1);
			for(int i=1;i<=cc;i++) sum-=z1[i];
		}
		else if(s2>cu)
		{
			cc=s2-cu;
			sort(z2+1,z2+s2+1);
			for(int i=1;i<=cc;i++) sum-=z2[i];
		}
		else if(s3>cu)
		{
			cc=s3-cu;
			sort(z3+1,z3+s3+1);
			for(int i=1;i<=cc;i++) sum-=z3[i];
		}
		cout << sum << endl ;
	}
	return 0;
}
