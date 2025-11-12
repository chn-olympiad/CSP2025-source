#include <bits/stdc++.h>
using namespace std;
int cnt1,cnt2,cnt3,n;
int a,b,c;
priority_queue<int,vector<int>,greater<int>> p1,p2,p3;
int t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		while(!p1.empty()) p1.pop();
		while(!p2.empty()) p2.pop();
		while(!p3.empty()) p3.pop();
		int ans=0;
		cnt1=cnt2=cnt3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a>=b&&a>=c)
			{
				cnt1++;
				p1.push(min(a-b,a-c));
				ans+=a;
			}
			else if(b>=a&&b>=c)
			{
				cnt2++;
				p2.push(min(b-a,b-c));
				ans+=b;
			}
			else
			{
				cnt3++;
				p3.push(min(c-a,c-b));
				ans+=c;
			}
		}
		while(cnt1>n/2)
		{
			cnt1--;
			ans=ans-p1.top();
			p1.pop();
		}
		while(cnt2>n/2)
		{
			cnt2--;
			ans=ans-p2.top();
			p2.pop();
		}
		while(cnt3>n/2)
		{
			cnt3--;
			ans=ans-p3.top();
			p3.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
