#include<bits/stdc++.h>
#define int long long
using namespace std;
const int base=131,p=998244353;
int n,q,hash1[500009],hash2[500009],ans,st1[40009][200],f[500009],vis[500009];
pair<int,int> s[500009],len[500009];
string c[200009],d[200009],ta,tb,st[40019];
int power(int x,int y)
{
	if(y==0)
	{
		return 1;
	}
	int mid=power(x,y>>1)%p;
	mid=mid*mid%p;
	if(y&1)
	{
		mid=mid*x%p;
	}
	return mid;
}
int tiint(string x)
{
	int re=0;
	for(int i=0;i<x.size();i++)
	{
		re=(re*base+(x[i]-'a'+1))%p;
	}
	return re;
}
void dfs(int x)
{
	if(hash1[ta.size()]==hash2[tb.size()])
	{
		ans++;
//		cout<<ta<<endl;
	}
	if(x>=40007)
	{
		return ;
	}
	for(int i=1;i<=ta.size();i++)
	{
		for(int b=1;b<=ta.size();b++)
		{
			st1[x][b]=hash1[b];
		}
		st[x]=ta;
		for(int j=1;j<=n;j++)
		{
			if(f[j])
			{
				continue;
			}
			int flag=0;
			for(int b=max((long long)1,i-len[j].first+1);b<=i;b++)
			{
				if(vis[b])
				{
					flag=1;
				}
			}
			if(flag==0&&i-len[j].first>=0&&(hash1[i]-hash1[i-len[j].first]*power(base,len[j].first)%p+p)%p==s[j].first)
			{
			//	cout<<i<<' '<<ta<<' '<<c[j]<<' '<<d[j]<<endl;
				f[j]=1;
				for(int b=i-len[j].first+1;b<=ta.size();b++)
				{
					if(b<=i)
					{
						hash1[b]=(hash1[b-1]*base+d[j][b-(i-len[j].first+1)]-'a'+1)%p;
						ta[b-1]=d[j][b-(i-len[j].first+1)];
						vis[b]=1;
					}
					else
					{
						hash1[b]=(hash1[b-1]*base+ta[b-1]-'a'+1)%p;
					}
				}
		//		cout<<ta<<endl;
				dfs(x+1);
				for(int b=1;b<=ta.size();b++)
				{
					hash1[b]=st1[x][b];
				}
				for(int b=i-len[j].first+1;b<=i;b++)
				{
					ta[b-1]=st[x][b-1];
					vis[b]=0;
				}
				f[j]=0;
			}
		}
	}
	return ;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>d[i];
		s[i]={tiint(c[i]),tiint(d[i])};
		len[i]={c[i].size(),d[i].size()};
	}
	while(q--)
	{
		cin>>ta>>tb;
		if(ta.size()>=10000)
		{
			cout<<0<<'\n';
			continue;
		} 
		for(int i=1;i<=ta.size();i++)
		{
			hash1[i]=(hash1[i-1]*base+ta[i-1]-'a'+1)%p;
		}
		for(int i=1;i<=tb.size();i++)
		{
			hash2[i]=(hash2[i-1]*base+tb[i-1]-'a'+1)%p;
		}
		dfs(0);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
