#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define dow(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int N=5e6+5,M=4e5+5,base=13331,p=998244353;
string s,t;
int n,q;
int hs1,hs2,Hs1[N],Hs2[N];
int _pow[N];
map<pair<int,int>,int> mp;
map<int,int> mp2;
string ss[M],tt[M];
int get1(int l,int r)
{
	if(l>r) return -1;
	return ((Hs1[r]-Hs1[l-1]*_pow[r-l+1]%p)+p)%p;
}
int get2(int l,int r)
{
	if(l>r) return -2;
	return ((Hs2[r]-Hs2[l-1]*_pow[r-l+1]%p)+p)%p;
}
void solve1()
{
	_pow[0]=1;
	rep(i,1,N-5) _pow[i]=_pow[i-1]*base%p;
	rep(i,1,n)
	{
		s=ss[i],t=tt[i];
		int len=s.size();
		hs1=hs2=0;
		rep(j,0,len-1)
		  hs1=(hs1*base+s[j])%p,
		  hs2=(hs2*base+t[j])%p;
		mp[{hs1,hs2}]++;
	}
	int l,r;
	int ans=0;
	if(q==1)
	{
		s=ss[1+n],t=tt[1+n];
		int lens=s.size(),lent=t.size();
		s=" "+s,t=" "+t;
		if(lens!=lent) {puts("0");return;;}
		rep(j,1,lens)
		  Hs1[j]=(Hs1[j-1]*base+s[j])%p,
		  Hs2[j]=(Hs2[j-1]*base+t[j])%p;
		r=1;
		l=lens;
		rep(j,1,lens)
		  if(s[j]!=t[j])
		  {
		  	l=j;
		  	break;
		  }
		dow(j,lens,1)
		  if(s[j]!=t[j])
		  {
		  	r=j;
		  	break;
		  }
		rep(i,1,n)
		{
			s=ss[i],t=tt[i];
			int len=s.size();
			hs1=hs2=0;
			rep(j,0,len-1)
		  	  hs1=(hs1*base+s[j])%p,
		  	  hs2=(hs2*base+t[j])%p;
//		  	cout<<hs1<<" "<<hs2<<endl;
		  	rep(ll,1,l)
		  	{
		  		int rr=ll+len-1;
		  		if(rr<r) continue;
//		  		cout<<ll<<" "<<rr<<endl;
		  		if(get1(ll,rr)==hs1&&get2(ll,rr)==hs2) ans++;
			}
		}
		cout<<ans;
		return;
	}
	rep(i,1,q)
	{
		ans=0;
		s=ss[i+n],t=tt[i+n];
		int lens=s.size(),lent=t.size();
		s=" "+s,t=" "+t;
		if(lens!=lent) {puts("0");continue;}
		rep(j,1,lens)
		  Hs1[j]=(Hs1[j-1]*base+s[j])%p,
		  Hs2[j]=(Hs2[j-1]*base+t[j])%p;
		r=1;
		l=lens;
		rep(j,1,lens)
		  if(s[j]!=t[j])
		  {
		  	l=j;
		  	break;
		  }
		dow(j,lens,1)
		  if(s[j]!=t[j])
		  {
		  	r=j;
		  	break;
		  }
		rep(ll,1,l)
		  rep(rr,r,lens)
		  {
		  	ans+=mp[{get1(ll,rr),get2(ll,rr)}];
		  }
		cout<<ans<<endl;
	}
	return;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	rep(i,1,n+q) cin>>ss[i]>>tt[i];
	bool vis=1;
	solve1();
	return 0;
}