#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define ull unsigned long long
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=2e5+10;
const int maxm=5e6+10;
ull p[maxm];
const int mod=1e9+7;
struct Hash
{
	ull hs[maxm];
	ull get(int l,int r)
	{
		ull res=hs[r]-hs[l-1]*p[r-l+1]%mod;
		return (res%mod+mod)%mod;
	}
	void build(string s)
	{
		int len=s.size();
		s=" "+s;
		for(int i=1;i<=len;i++) hs[i]=hs[i-1]*131+s[i],hs[i]%=mod;
	}
}hsb;
ull hss(string s)
{
	ull res=0;
	for(int i=0;s[i];i++) res*=131,res+=s[i],res%=mod;
	return res;
}
#define umap unordered_map
#define pss pair<string,string>
struct st
{
	ull u,v;
	ull wq,wh;
	bool operator<(const st &a) const
	{
		if(u!=a.u) return u<a.u;
		if(v!=a.v) return v<a.v;
		if(wq!=a.wq) return wq<a.wq;
		return wh<a.wh;
	}
};
map<st,int> dy;
ull hsq,hsh;
int len1=0,len2=0;
pss cf(string a,string b)
{
	hsq=0,hsh=0;
	if(a==b) return {"",""};
	int pos1;
	for(int i=0;a[i];i++)
	if(a[i]!=b[i])
	{
		pos1=i;
		break;
	}
	int pos2;
	for(int i=a.size()-1;i>=0;i--)
	if(a[i]!=b[i])
	{
		pos2=i;
		break;
	}
	string A="",B="";
	for(int i=pos1;i<=pos2;i++) A+=a[i],B+=b[i];
	string wq="",wh="";
	for(int i=0;i<pos1;i++) wq+=a[i];
	for(int i=pos2+1;i<a.size();i++) wh+=a[i];
	hsq=hss(wq),hsh=hss(wh);
	len1=wq.size(),len2=wh.size();
	return {A,B};
}
string a[maxn],b[maxn];
ull hs1[maxn],hs2[maxn],hsz1[maxn],hsz2[maxn];
int lenq[maxn],lenh[maxn];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Ios();
	int n,q;
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<=5e6;i++) p[i]=p[i-1]*131,p[i]%=mod;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(a[i]==b[i])
		{
		continue;
		}
		pss g=cf(a[i],b[i]);
		hs1[i]=hsq,hs2[i]=hsh;
		hsz1[i]=hss(g.fir);hsz2[i]=hss(g.sec);
		lenq[i]=len1,lenh[i]=len2;
		//cerr<<hs1[i]<<" "<<hs2[i]<<" "<<hsz1[i]<<" "<<hsz2[i]<<" "<<lenq[i]<<" "<<lenh[i]<<"\n";
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int N=t1.size();
		hsb.build(t1);
		pss u=cf(t1,t2);
		ull nd1=hss(u.fir),nd2=hss(u.sec);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==b[i]) continue;
			if(hsz1[i]==nd1&&hsz2[i]==nd2)
			{
				int l1=len1-lenq[i]+1,r1=len1,l2=N-len2+1,r2=N-len2+1+lenh[i]-1;
				if(l1>=1&&r1<=N&&l2>=1&&r2<=N)
				if(hsb.get(l1,r1)==hs1[i]&&hsb.get(l2,r2)==hs2[i])
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
5
aabcaa aacdaa
addabadd addcdadd
addabad addcdad
*/