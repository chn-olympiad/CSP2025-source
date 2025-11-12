#include <bits/stdc++.h>
using namespace std;
int MOD=998244353;
int n,m;
string s;
int c[510];
long long ans;
struct Node
{
	Node *pre;
	Node *nxt;
	int id; 
};
Node p[510];
void dfs(int x,int hf,int fail)
{
	if(x==n)
	{
		if(hf>=m) ++ans;
		return;
	}
	Node *r=&p[0];
	r=r->nxt;
	while(r->id!=0x3f3f3f3f)
	{
		r->nxt->pre=r->pre;
		r->pre->nxt=r->nxt;
		if((fail<c[r->id])&&(s[x]=='1'))
			dfs(x+1,hf+1,fail);
		else
		{
			dfs(x+1,hf,fail+1);
		}
		r->nxt->pre=r;
		r->pre->nxt=r;
		r=r->nxt;
	}
}
void solve1()
{
	ans=0;
	dfs(0,0,0);
	cout<<ans;
}
void solve2()
{
	long long res=1;
	for (int i=0;i<n;++i)
	{
		if((s[i]!='1')||(c[i+1]==0))
		{
			cout<<0;
			return;
		}
		res*=(i+1);
		res%=MOD;
	}
	cout<<res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	p[0].id=0;
	p[0].nxt=&p[1];
	for (int i=1;i<=n;++i)
	{
		p[i].id=i;
		p[i].nxt=&p[i+1];
		p[i].pre=&p[i-1];
		cin>>c[i];
	}
	p[n+1].id=0x3f3f3f3f;
	p[n+1].pre=&p[n];
	if(n<=11) solve1();
	else if(n==m) solve2();
	return 0;
}
