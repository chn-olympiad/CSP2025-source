#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll base=133;
#define mod 2833000039
string t2,t1,s1[200005],s2[200005];
ll hs[2000005][2][2],n,q,l[200005],r[200005],h[2],hh[2000005][2],p[200005];
ll calc(int l,int r,int op)
{
	return (hh[r][op]-(l==0?0:hh[l-1][op])*p[r-l+1]%mod+mod)%mod;
}
ll cl(int i,int l,int op)
{
	return hs[i][0][op]*p[l]%mod;
}
bool sol0(int i,int l_,int rr)
{
	int fl=l_-l[i],fr=s1[i].size()-r[i]+rr-1;
	if(fl<0||fr>=t1.size())return false;
//	cout<<fl<<" "<<fr<<" "<<calc(fl,fr,0)<<" "<<hs[i][0][0]<<"\n";
	return calc(fl,fr,0)==hs[i][0][0];
}
bool sol1(int i,int l_,int rr)
{
	int fl=l_-l[i],fr=s1[i].size()-r[i]+rr-1;
	if(fl<0||fr>=t2.size())return false;
//	cout<<fl<<" "<<fr<<" "<<calc(fl,fr,1)<<" "<<hs[i][0][1]<<"\n";
	return calc(fl,fr,1)==hs[i][0][1];
}
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
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++)
		{
			hs[i][0][0]=(hs[i][0][0]*base+s1[i][j])%mod;
			hs[i][0][1]=(hs[i][0][1]*base+s2[i][j])%mod;
		}
//		cout<<hs[i][0][0]<<" "<<hs[i][0][1]<<"\n";
		r[i]=s1[i].size()-1;
		while(s1[i][l[i]]==s2[i][l[i]])l[i]++;
		while(s1[i][r[i]]==s2[i][r[i]]&&r[i]>=l[i])r[i]--;
		for(int j=l[i];j<=r[i];j++)
		{
			hs[i][1][0]=(hs[i][1][0]*base+s1[i][j])%mod;
			hs[i][1][1]=(hs[i][1][1]*base+s2[i][j])%mod;
		}
	}
//	cout<<"*\n";
	p[0]=1;
	for(int i=1;i<=n;i++)p[i]=p[i-1]*base%mod;
	for(;q--;)
	{
		cin>>t1>>t2;
//		cout<<"*************\n";
		if(t1.size()!=t2.size()){cout<<"0\n";continue;}
		int l_=0,r_=t1.size()-1,len=t1.size(),ans=0;
		while(t1[l_]==t2[l_])l_++;
		while(t1[r_]==t2[r_])r_--;
		hh[0][0]=hh[0][1]=h[0]=h[1]=0;
		for(int i=0;i<t1.size();i++)
		{
			hh[i][0]=(hh[max(i-1,0)][0]*base+t1[i])%mod;
			hh[i][1]=(hh[max(i-1,0)][1]*base+t2[i])%mod;
//			cout<<hh[i][0]<<" "<<hh[i][1]<<"\n";
		}
//		cout<<"*\n";
		for(int i=l_;i<=r_;i++)
		{
			h[0]=(h[0]*base+t1[i])%mod;
			h[1]=(h[1]*base+t2[i])%mod;
		}
		for(int i=1;i<=n;i++)
		{
			if(h[0]==hs[i][1][0]&&h[1]==hs[i][1][1])ans+=sol0(i,l_,r_)&&sol1(i,l_,r_);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

