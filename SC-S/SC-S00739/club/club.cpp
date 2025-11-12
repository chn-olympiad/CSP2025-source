#include <bits/stdc++.h>
using namespace std;

struct stu
{
	int a,b,c;
}s[100005];
int n,t,flag=2,ans,minn;
bool cmp(stu x,stu y)
{
	return x.a>y.a;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			if (s[i].b==0&&s[i].c==0&&flag==2)
			{
				flag=2;
			}
			else
			{
				flag=0;
			}
		}
		if (flag==2)
		{
			sort(s+1,s+1+n,cmp);
			for (int i=1;i<=n/2;i++)
			{
				ans+=s[i].a;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}