#include<bits/stdc++.h> 
using namespace std;
int t,n,ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		while(n--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			ans+=max(a,max(b,c)); 
		}
	}
	return 0;
}
