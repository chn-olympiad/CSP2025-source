#include<bits/stdc++.h>
using namespace std;
int t,n,qj[100086];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int a=0,b=0,ans=0;
		cin>>n;
		for(int i=1,x,y,z;i<=n;i++)
		{
			cin>>x>>y>>z;
			qj[i]=x;
		}
		sort(qj+1,qj+n+1,cmp);
		for(int i=1;i<=n/2;i++)	ans+=qj[i];
		cout<<ans<<endl;
	}
	return 0;
}