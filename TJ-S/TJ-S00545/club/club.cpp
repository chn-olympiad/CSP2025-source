#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,a,b,c,t;
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
			ans+=max(a,max(b,c));
		}
		cout<<ans;
	}
	return 0;
 } 
