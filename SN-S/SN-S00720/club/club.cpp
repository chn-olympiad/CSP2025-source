#include <bits/stdc++.h>
using namespace std;

int t,n;
const int C=100010;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		if(n==2)
		{
			int p[35][4],q[4]={0,0,0,0},a,b,a1,a2,b1,b2;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i][0]>>p[i][1]>>p[i][2];
			a=max(max(p[i][0],p[i][1]),p[i][2]);
			if(a==p[i][0])
			{
				q[0]++;
				b=max(p[i][1],p[i][2]);
			} 
			else if(a==p[i][1])
			{
				q[1]++;
				b=max(p[i][0],p[i][2]);
			} 
			else
			{
				q[2]++;
				b=max(p[i][1],p[i][0]);
			} 
			if(i==1)
			{
				a1=a;
				b1=b;
			} 
			else if(i==2)
			{
				a2=a;
				b2=b;
			} 
			if(q[0]==2 || q[1]==2 || q[2]==2)
			{
				ans=max((a1+b2),(a2+b1));
			}
			else
			{
				ans=a1+a2;
			}
			}
			cout<<ans<<endl;
			continue;
		}
		int p[C],a,b,c,q;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b>>c;
			p[i]=a;
		}
		sort(p,p+n);
		for(int j=n-1;j>=n/2;j--)
		{
			ans+=p[j];
		}
		cout<<ans<<endl;
	}
	return 0;
}
