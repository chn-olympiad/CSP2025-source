#include<bits/stdc++.h>
using namespace std;
long long sqr[5000001],B=2,M=1e9+7,n,Q,m,L,R,h1[5000001],h2[5000001],ans,id;
bool t;
string s1,s2,ss;
vector<int> c[10000001];
struct pig
{
	long long x,y,l;
}a[200001];
bool cmp(pig l,pig r)
{
	return l.l<r.l;
}
long long H(string s)
{
	long long HH=0;
	for(long long i=0;i<s.size();++i)
	  HH=(HH*B%M+s[i]-96)%M;
	return HH;
}
string in()
{
	char ch=getchar();
	int p=0;
	ss="";
	while(!islower(ch))
	  ch=getchar();
	while(islower(ch))
	  ss=ss+ch,ch=getchar();
	return ss;
}
bool ok(string s)
{
	for(int i=0;i<s.size();++i)
	  if(s[i]!='a'&&s[i]!='b')
	    return false;
	if(s.find(s.find('b')+1,'b')==-1&&s.find('b')!=-1)
	  return true;
	return false;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	sqr[0]=1;
	for(long long i=1;i<=5e6;++i)
	  sqr[i]=sqr[i-1]*B%M;
	cin>>n>>Q;
	for(long long i=1;i<=n;++i)
	{
		cin>>s1>>s2;
		a[i].x=H(s1);
		a[i].y=H(s2);
		a[i].l=s1.size();
		if(ok(s1)&&ok(s2))
		  c[s1.find('b')-s2.find('b')+5000000].push_back(s1.find('b'));
	}
	for(int i=0;i<=1e7;++i)
	  if(c[i].size())
	    sort(c[i].begin(),c[i].end());
	sort(a+1,a+1+n,cmp);
	while(Q--)
	{
		s1=in(),s2=in();
		if(s1.size()!=s2.size())
		{
			cout<<"0\n";
			continue;
		}
		m=s1.size();
		if(ok(s1)&&ok(s2))
		{
			id=s1.find('b')-s2.find('b')+5000000;
			cout<<upper_bound(c[id].begin(),c[id].end(),s1.find('b'))-c[id].begin()<<'\n';
			continue;
		}
		s1=" "+s1;
		s2=" "+s2;
		L=1;
		R=m;
		while(L<=R&&s1[L]==s2[L])
		  ++L;
		while(L<=R&&s1[R]==s2[R])
		  --R;
		h1[0]=h2[0]=0;
		for(long long i=1;i<=m;++i)
		  h1[i]=(h1[i-1]*B%M+s1[i]-96)%M;
		for(long long i=1;i<=m;++i)
		  h2[i]=(h2[i-1]*B%M+s2[i]-96)%M;
		ans=0;
		for(long long i=1;i<=n;++i)
		  if(a[i].l>R-L)
		  {
			t=false;
			for(long long j=1;!t&&j<=m-a[i].l+1;++j)
			  if(j<=L&&j+a[i].l-1>=R&&(h1[j+a[i].l-1]-h1[j-1]*sqr[a[i].l]%M+M)%M==a[i].x&&(h2[j+a[i].l-1]-h2[j-1]*sqr[a[i].l]%M+M)%M==a[i].y)
			    ++ans,t=true;
		  }
		cout<<ans<<'\n';
	}
	return 0;
}