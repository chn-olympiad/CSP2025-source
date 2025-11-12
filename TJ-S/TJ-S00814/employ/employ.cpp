#include <bits/stdc++.h> 

using namespace std;
int t,n,a[100005],b[100005],c[100005];
bool cmd(int a,int b)
{
	return (a>b);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,cmd);
		sort(b+1,b+n+1,cmd);
		int ans=0;
		for(int i=1;i<=n/2;i++)
		{
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
