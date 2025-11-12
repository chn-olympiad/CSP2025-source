#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define mod 1000000007
#define pii pair<int,int>
using namespace std;

inline int read()
{
	int x=0,f=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?-x:x;
}
int n,q;
string s[200005][3],t[3];
const int P=13331;
unsigned long long ha[maxn],ha2[maxn];
unsigned long long hs1[maxn],hs2[maxn],p[maxn];
int len1,len2;
int l,r;
unsigned long long getha1(int l,int r)
{
	return ha[r]-ha[l-1]*p[r-l+1];
}
unsigned long long getha2(int l,int r)
{
	return ha2[r]-ha2[l-1]*p[r-l+1];
}
ll ans=0;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=2000;i++)
	{
		p[i]=p[i-1]*P;
	}
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		int len=s[i][1].length();
		s[i][1]=" "+s[i][1];
		s[i][2]=" "+s[i][2];
		for(int j=1;j<=len;j++)
		{
			
			hs1[i]=hs1[i]*P+s[i][1][j]-'a'+1;
			hs2[i]=hs2[i]*P+s[i][2][j]-'a'+1;
		}
	}
//	cout<<hs1[2];
	while(q--)
	{
		ans=0;
		cin>>t[1]>>t[2];
		t[1]=" "+t[1];t[2]=" "+t[2];
		len1=t[1].length(),len2=t[2].length();
		if(len1!=len2)
		{
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=len1;i++)
		{
			ha[i]=ha[i-1]*P+t[1][i]-'a'+1;
			ha2[i]=ha2[i-1]*P+t[2][i]-'a'+1;
		}
		for(int i=1;i<=len1;i++)
		{
			if(t[1][i]!=t[2][i]) {l=i;break;}
		}
		for(int i=len1;i>=1;i--)
		{
			if(t[1][i]!=t[2][i]) {r=i;break;}
		}
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int lee=s[j][1].length();
				if(i-lee<-1) continue;
//				cout<<i<<' '<<j<<' '<<i-lee+1<<' '<<i<<'\n';
//				cout<<hs1[j]<<' '<<getha1(i-lee+2,i)<<'\n';
				if(getha1(i-lee+2,i)==hs1[j]&&getha2(i-lee+2,i)==hs2[j]&&i>=r&&i-lee+2<=l)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}