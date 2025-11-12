#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#define pb push_back
struct pii {int fr,se;};
bool operator < (pii a,pii b) {return a.fr==b.fr?a.fr<b.fr:a.se<b.se;}
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,ans;
int vis[1000],s[1000],up[1000];
void solve(int p,int c)
{
	if (p>n)
	{
		ans+=(c>=m);
		return;
	}
	int v=p-1-c;
	for (int i=1;i<=n;i++) if (!vis[i])
	{
		bool cn=((up[i]>v)&&s[p]);
		vis[i]=1;
//		cout<<p<<" "<<i<<" "<<cn<<" "<<c<<endl;
		solve(p+1,c+cn);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	string ss;cin>>ss;
	for (int i=1;i<=n;i++) s[i]=ss[i-1]-'0';
	for (int i=1;i<=n;i++) cin>>up[i];
	solve(1,0);
	cout<<ans;
	return 0;
}
