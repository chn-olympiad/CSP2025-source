//SN-S00739 陈和骏 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N=200010,p=131;
vector<ull> hs[N],Has;
ull powp[5000010];
map<pair<ull,ull>,vector<int> > mp;
string s1[N],s2[N];
int mn[N],mx[N];
ull get_s(int idx,int l,int r)
{
	if(l==0) return hs[idx][r];
	return hs[idx][r]-hs[idx][l-1]*powp[r-l+1];
}
ull get_t(int l,int r)
{
	if(l==0) return Has[r];
	return Has[r]-Has[l-1]*powp[r-l+1];
}
int rd()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c && c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
	}
	else if(x<10)
	{
		putchar(x+'0');
		return;
	}
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=rd(),q=rd();
	powp[0]=1;
	for(int i=1;i<=5e6;i++) powp[i]=powp[i-1]*p;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		if(s1[i]==s2[i]) continue;
		ull h=0;
		for(int j=0;j<s2[i].size();j++)
		{
			h=h*p+s2[i][j];
			hs[i].push_back(h);
		}
		int minn=1e9,maxx=0;
		for(int j=0;j<s1[i].size();j++)
		{
			if(s1[i][j]!=s2[i][j]) minn=min(minn,j),maxx=max(maxx,j);
		}
		mn[i]=minn,mx[i]=maxx;
		int val=get_s(i,minn,maxx);
		hs[i].clear();
		h=0;
		for(int j=0;j<s1[i].size();j++)
		{
			h=h*p+s1[i][j];
			hs[i].push_back(h);
		}
//		cout<<minn<<" "<<maxx<<" "<<get_s(i,minn,maxx)<<"\n";
		mp[{get_s(i,minn,maxx),val}].push_back(i);
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		Has.clear();
		ull h=0;
		for(int j=0;j<t2.size();j++)
		{
			h=h*p+t2[j];
			Has.push_back(h);
		}
		int minn=1e9,maxx=0;
		for(int j=0;j<t1.size();j++)
		{
			if(t1[j]!=t2[j]) minn=min(minn,j),maxx=max(maxx,j);
		}
		int val=get_t(minn,maxx);
		Has.clear();
		h=0;
		for(int j=0;j<t1.size();j++)
		{
			h=h*p+t1[j];
			Has.push_back(h);
		}
		int w=get_t(minn,maxx);
		int ans=0;
		for(int i:mp[{w,val}])
		{
			int idx=minn-mn[i];
			if(idx<0 || idx+s1[i].size()-1>=t1.size()) continue;
			if(get_t(idx,idx+s1[i].size()-1)==get_s(i,0,s1[i].size()-1))
			{
				ans++;
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
