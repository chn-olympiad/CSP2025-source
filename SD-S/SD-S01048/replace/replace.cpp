#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int base=2333;
const int N=2e5;
const int X=2e6;
int n,q;
string s[N+5][2];
ull hs[N+5][2];
int lens[N+5][2];
ull cal(string str,int len)
{
	ull res=0;
	for(int i=0;i<len;i++)
	{
		res=(res*base+str[i]-'a');
	}
	return res;
}
string a,b;
ull ha[X+5],hb[X+5];
int lena,lenb;
int cnt=0;
ull pw[N+5];
void solve()
{
	//cout<<0<<"\n";return;
	cnt=0;
	cin>>a>>b;
	lena=a.size();
	lenb=b.size();
	if(lena!=lenb)
	{
		cout<<0<<"\n";
		return;
	}
	ha[0]=a[0]-'a';
	for(int i=1;i<lena;i++)
	{
		ha[i]=ha[i-1]*base+a[i]-'a';
	}
	hb[0]=b[0]-'a';
	for(int i=1;i<lenb;i++)
	{
		hb[i]=hb[i-1]*base+b[i]-'a';
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=lena;j++)
		{
			if(pw[j]*(j==0?0:ha[j-1])+hs[i][0]==ha[j+lens[i][0]-1])
			{
				cnt+=(pw[j]*(j==0?0:ha[j-1])+hs[i][1]==hb[j+lens[i][1]]-1);
			}
		}
	}
	cout<<cnt<<"\n";
}
void init()
{
	pw[0]=1;
	for(int i=1;i<=X;i++)pw[i]=pw[i-1]*base;
}
signed main()
{
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	init();
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		lens[i][0]=s[i][0].size();
		lens[i][1]=s[i][1].size();
		hs[i][0]=cal(s[i][0],lens[i][0]);
		hs[i][1]=cal(s[i][1],lens[i][1]);
	}
	while(q--)
	{
		solve();
	}
	return 0;
}
