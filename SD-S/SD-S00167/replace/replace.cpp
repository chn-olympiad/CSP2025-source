#include<bits/stdc++.h>
using namespace std;
long long n,q,ans;
struct liu
{
	string a,b;
}s[200005],l[200005];
string st,en,mia,mib;
long long stt,enn;
bool ok=0;
map<string,map<string,vector<liu> > >e;
int main()
{
 	freopen("replace.in","r",stdin);
 	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
		st=en=mia=mib="";
		stt=enn=0;
		for(int j=0;j<(int)s[i].a.size();j++)
		{
			if(s[i].a[j]!=s[i].b[j])
			{
				stt=j;
				break;
			}
			st+=s[i].a[j];
		}
		for(int j=(int)s[i].a.size();j>=0;j--)
		{
			if(s[i].a[j]!=s[i].b[j])
			{
				enn=j;
				break;
			}
		}
		for(int j=enn+1;j<(int)s[i].a.size();j++)
		{
			en+=s[i].a[j];
		}
		for(int j=stt;j<=enn;j++)
		{
			mia+=s[i].a[j];
			mib+=s[i].b[j];
		}
		e[mia][mib].emplace_back(liu{st,en});
	}
//	return 0;
	for(int i=1;i<=q;i++)
	{
		cin>>l[i].a>>l[i].b;
		st=en=mia=mib="";
		stt=enn=0;
		for(int j=0;j<(int)l[i].a.size();j++)
		{
			if(l[i].a[j]!=l[i].b[j])
			{
				stt=j;
				break;
			}
			st+=l[i].a[j];
		}
		for(int j=(int)l[i].a.size();j>=0;j--)
		{
			if(l[i].a[j]!=l[i].b[j])
			{
				enn=j;
				break;
			}
		}
		for(int j=enn;j<(int)l[i].a.size();j++)
		{
			en+=l[i].a[j];
		}
		for(int j=stt;j<=enn;j++)
		{
			mia+=l[i].a[j];
			mib+=l[i].b[j];
		}
		ans=0,ok=1;
		for(liu j:e[mia][mib])
		{
			ok=1;
			for(int k=stt-1;k>=stt-(int)j.a.size();k--)
			{
				if(j.a[k-stt+(int)j.a.size()]!=l[i].a[k])
				{
					ok=0;
					break;
				}
			}
			if(!ok)continue;
			for(int k=enn+1;k<=enn+(int)j.b.size();k++)
			{
				if(j.b[k-enn-1]!=l[i].a[k])
				{
					ok=0;
					break;
				}
			}
			if(ok)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

