#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct student{
	int al1,al2,al3;
}s[1000005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].al1>>s[i].al2>>s[i].al3;
		}
		if(n==2)
		{
			ans=max(ans,max(s[1].al1,s[2].al2));
			ans=max(ans,max(s[1].al1,s[2].al3));
			ans=max(ans,max(s[1].al2,s[2].al3));
			cout<<ans;
			continue;
		}
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=max(max(s[i].al1,s[i].al2),s[i].al3);
		}
		cout<<sum;
	}
	return 0;
}
