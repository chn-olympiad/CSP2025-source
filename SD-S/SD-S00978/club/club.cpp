#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;//Ren5Jie4Di4Ling5%
const int N=1e5+10;
int n,a1[N],a2[N],a3[N];
int as,bs,cs;
pair<pair<int,int>,int> ch[N];//a,bÖ®¼äµÄ²î 
int ans=0;
void Clean()
{
	for(int i=1;i<=n;i++)
	{
		a1[i]=0;a2[i]=0;a3[i]=0;
	}
	ans=0;as=0;bs=0;cs=0;
	return;
}
void dfs(int a,int s)
{
	if(a>n)
	{
		ans=max(ans,s);
		return;
	}
	if(as<n/2)
	{
		as++;
		dfs(a+1,s+a1[a]);
		as--;
	}
	if(bs<n/2)
	{
		bs++;
		dfs(a+1,s+a2[a]);
		bs--;
	}
	if(cs<n/2)
	{
		cs++;
		dfs(a+1,s+a3[a]);
		cs--;
	}
	return;
}
int work()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
	bool I1=0,I2=0,I3=0;
	int y=0;
	for(int i=1;i<=n;i++)
	{
		if(a2[i]) I2=1;
		if(a3[i]) I3=1;
	}
	if(!I2 and !I3)
	{
		for(int i=1;i<=n;i++) a1[i]*=-1;
		sort(a1+1,a1+n+1);
		for(int i=1;i<=n/2;i++)
		{
			ans-=a1[i];
		}
		cout<<ans<<endl;
		Clean();
		return 0;
	}
	if(!I3)
	{
		for(int i=1;i<=n;i++)
		{
			ch[i].fi.fi=-abs(a2[i]-a1[i]);
			if(a2[i]>a1[i]) ch[i].fi.se=2;
			else ch[i].fi.se=1;
			ch[i].se=i;
		}
		sort(ch+1,ch+1+n);
		int aa=0,bb=0,ji;
		for(int i=1;i<=n;i++)
		{
			if(aa==n/2 or bb==n/2)
			{
				ji=i;
				break;
			}
			if(ch[i].fi.se==1)
			{
				aa++;
				ans+=a1[ch[i].se];
				//cout<<"A"<<" "<<ch[i].se<<endl;
			}
			else
			{
				bb++;
				ans+=a2[ch[i].se];
				//cout<<"B"<<" "<<ch[i].se<<endl;
			}
		}
		if(aa==n/2)
		{
			for(int i=ji;i<=n;i++) ans+=a2[ch[i].se];
		}
		else
		{
			for(int i=ji;i<=n;i++) ans+=a1[ch[i].se];
		}
		cout<<ans<<endl;
		Clean();
		return 0;
	}
	if(n<=20)
	{
		dfs(0,0);
		cout<<ans<<endl;
		Clean();
		return 0;
	}
	for(int i=1;i<=n;i++) ans+=max(a1[i],max(a2[i],a3[i]));
	cout<<ans<<endl;
	Clean();
	return 0;
} 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		work();
	}
	return 0;
}
