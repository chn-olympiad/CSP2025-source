#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
const ll mod=9855943,p=13131;
ll fpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int n,q;
string s1[200010],s2[200010],l1,l2;
ll h1[200010],po[5000010],h2[5000010],inv[5000010];
void init()
{
	po[0]=inv[0]=1;
	for(int i=1;i<=5000005;++i)po[i]=po[i-1]*p%mod;
	inv[5000005]=fpow(po[5000005],mod-2);
	for(int i=5000004;i>=1;--i)inv[i]=(inv[i+1]*p)%mod;
}
ll gethashs(string s)
{
	int len=s.size();
	ll h=0;
	for(int i=0;i<len;++i)(h+=(s[i]-'a'+1)*po[i]%mod)%=mod;
	return h;
}
void gethashl()
{
	int len=l1.size();
	for(int i=0;i<len;++i)h2[i+1]=(h2[i]+(l1[i]-'`')*po[i]%mod)%mod;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	init();
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>s1[i]>>s2[i];
		h1[i]=gethashs(s1[i]);
	}
	while(q--)
	{
		cin>>l1>>l2;
		if(l1.size()!=l2.size())
		{
			cout<<"0\n";
			continue;
		}
		gethashl();
		int len=l1.size(),ans=0;
		for(int i=1;i<=n;++i)
		{
			int len1=s1[i].size();
			for(int j=1;j+len1-1<=len;++j)
			{
				if(((h2[j+len1-1]-h2[j-1])%mod+mod)%mod*inv[j-1]%mod==h1[i])
				{
					string l3=l1;
					for(int k=j-1;k<j+len1-1;++k)
					{
						l3[k]=s2[i][k-j+1];
					}
					if(l3==l2)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}//20~40pts?
