#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
 }
const int N=2e5+5;
//vector<int>nxt[N];完了KMP斜挂了
int n,q,hs[N][2],w1=113,w2=83;
struct node
{
	string p,q;
	int sz,h1,h2,h3,h4;
}a[N];
bool cmp(node x,node y)
{
	return x.sz<y.sz;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].p>>a[i].q;
		a[i].sz=a[i].p.size();
		for(int j=0;j<a[i].sz;j++)
		{
			a[i].h1=a[i].h1*w1+a[i].p[j];
			a[i].h2=a[i].h2*w2+a[i].p[j];
			a[i].h3=a[i].h3*w1+a[i].q[j];
			a[i].h4=a[i].h4*w2+a[i].q[j];
		}
	}
	sort(a+1,a+n+1,cmp);
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		int jz=1;
		int siz=x.size();
		int hs1=0,hs2=0;
		for(int i=0;i<=siz;i++)
		{
			hs1=hs1*w1+y[i];
			hs2=hs2*w2+y[i];
		}
		int l=-1,r=0;
		for(int i=0;i<siz;i++)
		{
			if(x[i]!=y[i])
			{
				if(l==-1)l=i;
				r=max(r,i);
			}
		}
//		cout<<l<<" "<<r<<'\n';
		if(l==r&&r==-1)
		{
			int ans=0;
			for(int i=1;i<=n;i++)if(a[i].h1==a[i].h3&&a[i].h4==a[i].h2)ans++;
			cout<<ans<<'\n';
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].sz<r-l+1)continue;
//			cout<<i<<'\n';
			for(int j=1;j<=a[i].sz-(r-l+1)+1;j++)
			{
//				cout<<a[i].p<<'\n';
				bool flag=0;
				for(int k=l;k<=r;k++)
				{
					if(a[i].p[k-l+j-1]!=x[k]||a[i].q[k-l+j-1]!=y[k])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)ans++;
			}
//			cout<<ans<<'\n';
		}
		cout<<ans<<'\n';
	}
//	for(int i=1;i<=n;i++)
//	{	球球了别挂分 
//		cin>>p[i]>>s[i];
//		sz[i]=p[i].size();
//		for(int j=1;j<=sz[i];j++)nxt[i].push_back(0);
//		for(int k=1,j=0;k<=sz[i];k++)
//		{
//			while(j!=0&&p[i][j+1]!=p[i][k])j=nxt[i][j],cout<<k<<' '<<j<<'\n';
//			if(p[i][j+1]==p[i][k])j++;
//			nxt[i][k]=j;
//		}
//		for(int j=1;j<=sz[i];j++)cout<<nxt[i][j]<<" ";cout<<'\n';
//	}
	return 0;
}

