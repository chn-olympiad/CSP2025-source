#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll sum=0,l=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')l=-1;c=getchar();}
	while(isdigit(c)){sum=(sum<<1)+(sum<<3)+(c^48);c=getchar();}
	return sum*l;
}
ll ch1[100100],ch2[100100],ch3[100100],cnt1,cnt2,cnt3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t=read();
	while(t--)
	{
		cnt1=cnt2=cnt3=0;
		ll a=read(),ans=0;
		for(ll i=1;i<=a;i++)
		{
			ll b=read(),c=read(),d=read();
			if(b>=max(c,d))ch1[++cnt1]=b-max(c,d),ans+=b;
			else if(c>=max(b,d))ch2[++cnt2]=c-max(b,d),ans+=c;
			else ch3[++cnt3]=d-max(b,c),ans+=d;
		}
		sort(ch1+1,ch1+cnt1+1);
		sort(ch2+1,ch2+cnt2+1);
		sort(ch3+1,ch3+cnt3+1);
		if(cnt1>a/2)for(ll i=1;i<=cnt1-a/2;i++)ans-=ch1[i];
		if(cnt2>a/2)for(ll i=1;i<=cnt2-a/2;i++)ans-=ch2[i];
		if(cnt3>a/2)for(ll i=1;i<=cnt3-a/2;i++)ans-=ch3[i];
		cout<<ans<<"\n";
	}
	return 0;
}
