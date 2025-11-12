#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
#define popcount __builtin_popcount
using namespace std;
const int N=500+10;
const int inf=0x3f3f3f3f3f3f3f3f;
const int p=998244353;
int n,m;
int c[N];
string s;
int mod(int x)
{
	while(x>=p) x-=p;
	while(x<0) x+=p;
	return x;
}
void add(int &x,int y)
{
	x+=y;
	while(x>=p) x-=p;
	while(x<0) x+=p;
}
int fac[N];
void init()
{
	fac[0]=1;
	for(int i=1;i<=500;i++) fac[i]=fac[i-1]*i%p;
}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	init();
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10)
	{
		int ans=0;
		int t[20];
		for(int i=1;i<=n;i++) t[i]=i; 
		do
		{
			int la=0;
			int num=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i]=='1'&&c[t[i]]>=i-la) num++,la=i;
			}
			ans+=(num>=m);
		}while(next_permutation(t+1,t+n+1));
		cout<<ans;
		return 0;
	}
	sort(c+1,c+n+1);
	bool tag=1;
	for(int i=1;i<=n;i++) tag&=(s[i]=='1');
	if(n==m)
	{
		if(!tag) cout<<0;
		else cout<<fac[n];
		return 0;
	}
	if(tag)
	{ 
		cout<<fac[n];
		return 0;
	}
	if(m==1)
	{
		int ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%p;
		int cnt=0;
		int num=1,tot=0;
		int pos=1;
		for(int i=1;i<=n;i++)
		{
			while(pos<=n&&c[pos]<=i-1) cnt++,pos++;
			if(s[i]=='1')
			{
				tot++;
				if(cnt) num=num*cnt%p,cnt--;
				else num=0;
			}
		}
		num=num*fac[n-tot]%p;
		cout<<mod(ans-num);
		return 0;
	}
	int ans=0;
	vector<int> po;
	for(int i=1;i<=n;i++) if(s[i]=='1') po.push_back(i);
	if(m>po.size())
	{
		cout<<0;
		return 0;
	}
	int k=po.size();
	for(int s=0;s<(1<<k);s++)
	{
		if(popcount(s)<m) continue;
		vector<int> t;
		int x=0;
		for(int i=0;i<k;i++)
		{
			if(s&(1<<i)) t.push_back(po[i]-x),x=po[i];
		}
		sort(t.begin(),t.end(),cmp);
		int pos=n;
		int num=0;
		int cnt=1;
		for(auto l:t)
		{
			while(pos&&c[pos]>=l) pos--,num++;
			cnt=cnt*num%p,num--;
		}
		cnt=cnt*fac[n-popcount(s)]%p;
		add(ans,((popcount(s)-m)%2==0?1:-1)*cnt);
	}
	cout<<ans;
	return 0;
}
