#include<bits/stdc++.h>
using namespace std;
int n,q,f=1,g,fff1,fff,ff1[200005],ff[200005],l,r,len;
string a[200005],b[200005],c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		g=0;
		for(int j=0;j<a[i].size();j++)
		{
			if(a[i][j]!='a' && (a[i][j]!='b' || (a[i][j]=='b' && g==1)))
			{
				f=0;
				break;
			}
			if(a[i][j]=='b')
			{
				g=1;
			}
		}
		g=0;
		for(int j=0;j<b[i].size();j++)
		{
			if(b[i][j]!='a' && (b[i][j]!='b' || (b[i][j]=='b' && g==1)))
			{
				f=0;
				break;
			}
			if(b[i][j]=='b')
			{
				g=1;
			}
		}
	}
	if(f==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<a[i].size();j++)
			{
				if(a[i][j]=='b')
				{
					ff1[i]=j;
					break;
				}
			}
			for(int j=0;j<b[i].size();j++)
			{
				if(b[i][j]=='b')
				{
					ff[i]=ff1[i]-j;
					break;
				}
			}
		}
		cout<<endl;
		while(q--)
		{
			cin>>c>>d;
			if(c.size()!=d.size())
			{
				cout<<0<<endl;
				continue;
			}
			len=c.size();
			for(int i=0;i<len;i++)
			{
				if(c[i]=='b')
				{
					fff1=i;
					break;
				}
			}
			for(int i=0;i<len;i++)
			{
				if(d[i]=='b')
				{
					fff=fff1-i;
					g=0;
					for(int j=1;j<=n;j++)
					{
						if(ff[j]==fff && len>=a[j].size() && fff1>=ff1[j] && len-fff1>=a[j].size()-ff1[j])
						{
							g++;
						}
					}
					cout<<g<<endl;
					break;
				}
			}
		}
		return 0;
	}
	while(q--)
	{
		cin>>c>>d;
		if(c.size()!=d.size())
		{
			cout<<0<<endl;
			continue;
		}
		len=c.size();
		l=0;
		r=0;
		for(int i=0;i<len;i++)
		{
			if(c[i]!=d[i])
			{
				break;
			}
			l++;
		}
		for(int i=len-1;i>=0;i--)
		{
			if(c[i]!=d[i])
			{
				break;
			}
			r++;
		}
		g=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].size()<len-l-r)
			{
				continue;
			}
			if(a[i].size()>len)
			{
				continue;
			}
			for(int j=max(0,len-int(a[i].size())-r);j<=l;j++)
			{
				f=1;
				for(int k=j;k<=j+a[i].size()-1;k++)
				{
					if(c[k]!=a[i][k-j])
					{
						f=0;
						break;
					}
				}
				if(f==1)
				{
					for(int k=j;k<=j+a[i].size()-1;k++)
					{
						if(d[k]!=b[i][k-j])
						{
							f=0;
							break;
						}
					}
				}
				if(f==1)
				{
					g++;
				}
			}
		}
		cout<<g<<endl;
	}
	return 0;
}
