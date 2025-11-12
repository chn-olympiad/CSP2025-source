#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+3;

struct xing{
	string x;
	string y;
};
xing s[N],k[N];
string get(string s,int l,int r)
{
	string ans="";
	for(int i=l-1;i<r;i++)ans+=s[i];
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].x>>s[i].y;
		for(int j=1;j<i;j++)
		{
			if(s[j].y==s[i].x)s[j].y=s[i].x;
			if(s[j].x==s[i].y)s[j].x=s[i].y;
		}
	}
	for(int i=1;i<=m;i++)cin>>k[i].x>>k[i].y;
	
	string a,b,c,d,as,bs;
	for(int i=1;i<=m;i++)
	{
		ans=0;
		a=k[i].x;
		d=k[i].y;
		
			for(int l=1;l<=n;l++)
			{
				b=s[l].x;
				c=s[l].y;
				if(l-1+b.size()<=a.size())
				{
					as=get(a,l,l-1+b.size());
					bs=get(d,l,l-1+b.size());
					if(b==as && bs==c)ans++;
				}
			}
		
		cout<<ans<<endl;
	}
}
