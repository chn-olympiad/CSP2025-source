#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const LL N=2e5+9;
LL n,q,l,r;
string s1[N],s2[N],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(LL i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<"0\n";
			break;
		}
		LL p=-1,ans=0;
		for(LL i=0;i<t1.size();i++)
		{
			if(t1[i]!=t2[i])
			{
				l=i;
				break;
			}
		}
		for(LL i=t1.size()-1;i>=0;i--)
		{
			if(t1[i]!=t2[i])
			{
				r=i;
				break;
			}
		}
		string y,yy;
		for(LL i=l;i<=r;i++)
		{
			p++;
			y[p]=t1[i];
			yy[p]=t2[i];
		}
		for(LL i=1;i<=n;i++)
		{
			if(s1[i]==y&&s2[i]==yy) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}