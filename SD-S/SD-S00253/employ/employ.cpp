#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, a[N];
string s;
bool vis[N];
int read()
{
	int n=0, f=1; char c=getchar();
	while(c<'0'||c>'9') f-=2*(c=='-'), c=getchar();
	while(c>='0'&&c<='9') n=n*10+c-'0', c=getchar();
	return n*f;
}
int ss(int c,int u)
{
	if(u>n&&n-c>=m) return 1;
	if(u>n) return 0;
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i] = 1;
		if(s[u-1]=='0') ans += ss(c+1,u+1);
		else if(c>=a[i]) ans += ss(c+1,u+1);
		else ans += ss(c,u+1);
		vis[i] = 0;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) a[i]=read();
	cout<<ss(0,1);
	return 0;
}

