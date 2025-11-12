#include<bits/stdc++.h>
using namespace std;
const int N=978231543,M=89347;
#define ll long long
int n,q;
string s1,s2;
map<ll,int> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int len;
	ll hs1,hs2;
	for(int i=1;i<=n;i++)
	{
		hs1=hs2=0;
		cin>>s1>>s2;
		len=s1.length();
		for(int j=0;j<len;j++)
		{
			hs1=(hs1*M+s1[j])%N;
			hs2=(hs2*M+s2[j])%N;
		}
		mp[hs1*1000000000+hs2]=1;
	}
	int id1,id2;
	ll ans;
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		len=s1.length();
		ans=0;
		for(id1=0;id1<len;id1++)
		{
			if(s1[id1]!=s2[id1])
			{
				break;
			}
		}
		for(id2=len-1;id2>=0;id2--)
		{
			if(s1[id2]!=s2[id2])
			{
				break;
			}
		}
		for(int j=0;j<=id1;j++)
		{
			hs1=hs2=0;
			for(int k=j;k<id2;k++)
			{
				hs1=(hs1*M+s1[k])%N;
				hs2=(hs2*M+s2[k])%N;
			}
			for(int k=id2;k<len;k++)
			{
				hs1=(hs1*M+s1[k])%N;
				hs2=(hs2*M+s2[k])%N;
				ans+=mp[hs1*1000000000+hs2];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
