#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int read()
{
	int t=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')t=t*10+c-'0',c=getchar();
	return t*f;
}
int t,n,mx,mx_,s1,s2,x,s[N],num,ans;
struct node
{
	int CLUB,val;
}c[N];
bool cmp(node x,node y)
{
	return x.val<y.val;
}
void init()
{
	ans=0,s[0]=s[1]=s[2]=0;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		init();
		n=read();
		for(int i=1;i<=n;i++)
		{
			mx=-1,mx_=-1;
			for(int v=0;v<3;v++)
			{
				x=read();
				if(x>mx)mx_=mx,mx=x,c[i].CLUB=v;
				else if(x>mx_)mx_=x;
			}
			s[c[i].CLUB]++;
			c[i].val=mx-mx_;
			ans+=mx;
		}
		s1=max(s[0],max(s[1],s[2]));
		if(s1==s[0])s2=0;
		else if(s1==s[1])s2=1;
		else s2=2;
		if(s1>n/2)
		{
			sort(c+1,c+1+n,cmp);
			num=0;
			for(int i=1;i<=n;i++)
			{
				if(num>=s1-n/2)break;
				if(c[i].CLUB==s2)num++,ans-=c[i].val;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}