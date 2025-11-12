#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define int long long
#define R(x) x=read()
#define W(X) write(x)
#define MAXN 1000010
inline int read()
{
	int x,y;
	x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') y=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	return x*y;
}
inline void write(int x)
{
	if(x<0) {putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void dfs(int);
int n,m;
string s;
int c[MAXN];
int a[MAXN];
int ans=0;
bool vis[MAXN];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	R(n);R(m);
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
		R(c[i]);
	dfs(1);
	cout<<ans;
	return 0;
}
void dfs(int st)
{
	if(st==n+1)
	{
		int gp=0,cnt=0;
		for(int i=1;i<=n;i++)
			if(gp>=c[a[i]])
			{
				gp++;
				continue;
			}
			else 
			{
				if(s[i]=='0') gp++;
				else cnt++;
			}
//		for(int i=1;i<=n;i++)
//			cout<<a[i]<<' ';
//		cout<<cnt<<endl;
		if(cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		a[st]=i;
		vis[i]=true;
		dfs(st+1);
		vis[i]=false;
	}
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
