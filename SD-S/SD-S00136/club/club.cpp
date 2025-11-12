#include<bits/stdc++.h>
using namespace std;
int T,s[100050][4],sk[4][100050];
long long sov(int j,int m,int n)
{
	long long k=0;
	sort(sk[j]+1,sk[j]+m+1);
	for(int i=1;i<=m-n/2;i++)
	{
		k+=sk[j][i];
	}
	return k;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		long long ans=0,k=0;
		int n,x=0,y=0,z=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i][1]>>s[i][2]>>s[i][3];
			int a=s[i][1],b=s[i][2],c=s[i][3];
			if(a>=b&&a>=c)
			{
				ans+=a;
				x++;
				sk[1][x]=min(a-b,a-c);
			}
			else if(b>=a&&b>=c)
			{
				ans+=b;
				y++;
				sk[2][y]=min(b-a,b-c);
			}
			else if(c>=a&&c>=b)
			{
				ans+=c;
				z++;
				sk[3][z]=min(c-a,c-b);
			}
		}
		if(x>n/2) k=sov(1,x,n);
		if(y>n/2) k=sov(2,y,n);
		if(z>n/2) k=sov(3,z,n);
		cout<<ans-k<<"\n";
		for(int i=1;i<=n;i++)
		{
			s[i][1]=s[i][2]=s[i][3]=sk[1][i]=sk[2][i]=sk[3][i]=0;
		}
	}
	return 0;
}
/*

*/
