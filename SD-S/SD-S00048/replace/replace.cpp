#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+10;
struct node{
	string s,t;
	string sa,sb;
	int lp,rp;
}p[M];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,fgg=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].s>>p[i].t;
		int l=0,r=p[i].s.size()-1,flag=0,fga=0,fgb=0;
		for(int j=0;j<=p[i].s.size()-1;j++)
		{
			if(p[i].s[j]>'b'||p[i].t[j]>'b') fgg=1;
			else if(p[i].s[j]=='b')
			{
				if(fga) fgg=1;
				else fga=1;
			}
			else if(p[i].t[j]=='b')
			{
				if(fgb) fgg=1;
				else fgb=1;
			}
			if(p[i].s[j]!=p[i].t[j])
			{
				if(!flag) l=j,flag=1;
				r=j;
			}
		}
		for(int j=l;j<=r;j++)
		{
			p[i].sa+=p[i].s[j];
			p[i].sb+=p[i].t[j];
		}
		p[i].lp=l;
		p[i].rp=p[i].s.size()-1-r;
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		string qa,qb,ta,tb;
		cin>>qa>>qb;
		int l=0,r=0,flag=0;
		for(int j=0;j<=qa.size()-1;j++)
		{
			if(qa[j]!=qb[j])
			{
				if(!flag) l=j,flag=1;
				r=j;
			}
		}
		for(int j=l;j<=r;j++)
		{
			ta+=qa[j];
			tb+=qb[j];
		}
//		for(int j=1;j<=n;j++)
//		{
//			string qs;
//			if(ta==p[j].sa&&tb==p[j].sb) 
//			{
//				for(int k=l-p[j].lp;k<=r+p[j].rp;k++)
//				{
//					qs+=qa[k];
//				}
//				if(qs==p[j].s) ans++;
//			}
//		}
		for(int j=1;j<=n;j++)
		{
			if(ta==p[j].sa&&tb==p[j].sb) 
			{
				ans++;
				int g=0;
				if(l-p[j].lp<0||r+p[j].rp>=qa.size())
				{
					ans--;
					continue;
				}
				if(!fgg) continue;
				for(int k=l-p[j].lp;k<=r+p[j].rp;k++)
				{
					if(p[j].s[g++]!=qa[k])
					{
						ans--;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

