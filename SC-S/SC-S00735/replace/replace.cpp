#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=1e7+10,W=26;
int n,qu;
string a,b;
int w[M],len=0,cnt[M];
int t[M][26],tot=0;
int fail[M];
queue<int> q;
void insert()
{
	int u=0;
	for(int i=0;i<len;i++)
	{
		int c=a[i]-'a';
		if(!t[u][c]) t[u][c]=++tot;
		u=t[u][c];
		c=b[i]-'a';
		if(!t[u][c]) t[u][c]=++tot;
		u=t[u][c];
	}
	cnt[u]++;
}
void build()
{
	for(int i=0;i<W;i++)
	{
		if(t[0][i]) q.push(t[0][i]);
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		cnt[x]+=cnt[fail[x]];
		for(int i=0;i<W;i++)
		{
			int p=t[x][i];
			if(p)
			{
				fail[p]=t[fail[x]][i];
				q.push(p);
			}
			else t[x][i]=t[fail[x]][i];
		}
	}
}
ll query(int l,int r)
{
	if(l>r||r<0||l>len-1) return 0;
	int u=0;ll ans=cnt[u];
	for(int i=l;i<=r;i++)
	{
		int c=a[i]-'a';
		u=t[u][c];
		c=b[i]-'a';
		u=t[u][c];
		ans+=cnt[u];
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>qu;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;len=a.length();
		insert();
	}
	build();
	while(qu--)
	{
		cin>>a>>b;len=a.length();
		int l=len,r=-1;
		for(int i=0;i<len;i++)
		{
			if(a[i]!=b[i])
			{
				if(l==len) l=i;
				r=i;
			}
		}
		ll sum12=query(0,r-1),sum23=query(l+1,len-1),sum1=query(0,l),sum2=query(l+1,r-1),sum3=query(r,len-1),sum123=query(0,len-1);
		cout<<sum123-sum2-sum1-sum3-(sum12+sum23-2*sum2-sum1-sum3)<<'\n';
	}
	return 0;
}