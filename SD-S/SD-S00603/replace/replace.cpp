#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+7;
ll n,q;
struct ss{
	string s1,s2;
	ll len;
}s[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].s1>>s[i].s2;
		s[i].len=s[i].s1.size();
	}
	while(q--)
	{
		string st1,st2;
		bool f=true;
		ll ans=0;
		cin>>st1>>st2;
		ll m1=st1.size(),m2=st2.size();
		if(m1!=m2)
		{
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<m1;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=0;k<i;k++)
				{
					if(st1[k]!=st2[k])
					{
						f=false;
						break;
					}
				}
				for(int k=0;k<s[j].len;k++)
				{
					if(st1[i+k]!=s[j].s1[k]||st2[i+k]!=s[j].s2[k]||i+k>=m1)
					{
						f=false;
						break;
					}
				}
				for(int k=i+s[j].len;k<m1;k++)
				{
					if(st1[k]!=st2[k])
					{
						f=false;
						break;
					}
				}
				if(f)
					ans++;
				f=true;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

