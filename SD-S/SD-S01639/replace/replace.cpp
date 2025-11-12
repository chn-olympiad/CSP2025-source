#include<bits/stdc++.h>
#define ll long long
#define fi(l) freopen(l".in","r",stdin)
#define fo(l) freopen(l".out","w",stdout)
using namespace std;
inline ll read()
{
	ll v=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
inline void out(ll x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x<10)putchar(x+'0');
	else
	{
		out(x/10);
		putchar(x%10+'0');
	}
}
inline ll ksm(ll a,ll b,ll p)
{
	ll ans=1;
	for(;b;b>>=1,a=a*a%p)
	{
		if(b&1)ans=ans*a%p;
	}
	return ans;
}
string s[200020][3];
int main()
{
	fi("replace");
	fo("replace");
	ll n=read(),q=read();
	for(ll i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		ll lt1=t1.size(),lt2=t2.size();
		if(lt1!=lt2)
		{
			out(0);
			cout<<'\n';
			continue;
		}
		ll ans=0;
		for(ll i=0;i<lt1;i++)
		{
			for(ll j=i;j<lt1;j++)
			{
				string x,y;
				for(ll k=i;k<=j;k++)
				{
					x+=t1[k];
					y+=t2[k];
				}
				string b_x,b_y,a_x,a_y;
				for(ll k=0;k<i;k++)
				{
					b_x+=t1[k];
					b_y+=t2[k]; 
				}
				for(ll k=j+1;k<lt1;k++)
				{
					a_x+=t1[k];
					a_y+=t2[k];
				}
				if(b_x!=b_y||a_x!=a_y)continue;
				if(x==y)continue;
				for(ll k=1;k<=n;k++)
				{
					if(x==s[k][1]&&y==s[k][2])
					{
						ans++;;
					}
				}
			}
		}
		out(ans);
		cout<<'\n';
	}
	return 0;
}
