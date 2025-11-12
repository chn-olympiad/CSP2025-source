#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull fpow(ull a,ull b);

const int N=2e5+2,L=5e6+2;
const ull Mod=201202067115;
int n,q,pos1,pos2,ans;
ull ha1[L],ha2[L],s1[N];
struct node{
	string s1,s2;
	ull h1,h2;
	int pos1,pos2,;
}s[N];
bool cmp(node x,node y);
string l1,l2;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].s1>>s[i].s2;
		s[i].h1=s[i].h2=0;
		for(int j=0;j<s[i].s1.size();j++)
		{
			s[i].h1=(s[i].h1*131+s[i].s1[j])%Mod;
			s[i].h2=(s[i].h2*131+s[i].s2[j])%Mod;
		}
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
		s1[i]=s[i].h1;
	while(q--)
	{
		cin>>l1>>l2;
		ha1[0]=l1[0],ha2[0]=l2[0];
		ans=0;
		for(int i=1;i<l1.size();i++)
		{
			ha1[i]=(ha1[i-1]*131+l1[i])%Mod;
			ha2[i]=(ha2[i-1]*131+l2[i])%Mod;
		}
		for(int i=0;i<l1.size();i++)
			if(l1[i]!=l2[i])
			{
				pos1=i;
				break;
			}
		for(int i=l1.size()-1;i>=0;i--)
			if(l1[i]!=l2[i])
			{
				pos2=i;
				break;
			}
		for(int i=0;i<=pos1;i++)
			for(int j=pos2;j<l1.size();j++)
			{
				ull t1=ha1[j]-(i?ha1[i-1]:0)*fpow(131,j-i+1);
				ull t2=ha2[j]-(i?ha2[i-1]:0)*fpow(131,j-i+1);
				int tt1=lower_bound(s1+1,s1+1+n,t1)-s1;
				int tt2=upper_bound(s1+1,s1+1+n,t1)-s1;
				for(int k=tt1;k<tt2;k++)
					if(t2==s[k].h2)
						ans++;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
ull fpow(ull a,ull b)
{
	ull res=1;
	while(b)
	{
		if(b&1)
			res=res*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}
	return res;
}
bool cmp(node x,node y)
{return x.h1<y.h1;}
