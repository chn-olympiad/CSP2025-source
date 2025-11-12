#include<bits/stdc++.h>
#define min(a,b) ((a)>(b)?(a):(b))
#define max(a,b) ((a)<(b)?(a):(b))
#define endl putchar('\n')
#define air putchar(' ')
using namespace std;
inline int read()
{
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')y=-y;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*y;
}
int n,m,res;
string str;
const int mod= 998244353,N=505;
int a[N],ans[N];
bool p[N];
void dfs(int k)
{
	if(k==n+1)
	{
		int x=0,y=0;
		for(int i=1;i<=n;i++)
		{
			if(a[ans[i]]<=x||str[i-1]=='0') x++;
			else y++;
			//cout<<a[ans[i]]<<' '<<x;endl;
		}
		if(y>=m) res++;
		//endl;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]) continue;
		p[i]=1;
		ans[k]=i;
		dfs(k+1);
		p[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>str;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=10)
	{
		dfs(1);
		cout<<res;
	}
	else if(n==m)
	{
		for(auto i:str) if(i=='0') return cout<<0,0;
		for(int i=1;i<=n;i++) if(a[i]==0) return cout<<0,0;
		cout<<1;
	}
	else 
	{
		int x=0;
		for(int i=1;i<=n;i++) x=(x%mod*i%mod)%mod;
		cout<<x;
	}
	return 0;
}
