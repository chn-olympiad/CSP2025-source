#include<bits/stdc++.h>
using namespace std;
int n,q,fl=1,f=1,a1[200010],b1[200010],d[200010];
struct A
{
	string a,b;
	int l;
}e[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i].a>>e[i].b;
		e[i].l=e[i].a.size();
		for(int j=0;j<e[i].l;j++)
			if(e[i].a[j]!='a')
				if(e[i].a[j]=='b')
				{
					if(fl==1)
						fl=-1,a1[i]=j;
					else if(fl==-1)
					{
						fl=0;
						break;
					}
				}
				else
				{
					fl=0;
					break;
				}
			else if(e[i].b[j]!='a')
				if(e[i].b[j]=='b')
				{
					if(f==1)
						f=-1,b1[i]=j;
					else if(f==-1)
					{
						f=0;
						break;
					}
				}
				else
				{
					fl=0;
					break;
				}
	}
	if(fl==-1&&f==-1)
	{
		for(int i=1;i<=n;i++)
			d[i]=a1[i]-b1[i];
		fl=1,f=1;
	}
	else
		fl=0;
	for(int i=1;i<=q;i++)
	{
		string x,y;
		int a2,b2;
		cin>>x>>y;
		int lx=x.size(),suc,s=0,ly=y.size();
		if(lx!=ly)
		{
			cout<<0<<'\n';
			continue;
		}
		if(fl==1&&f==1)
			for(int i=0;i<lx;i++)
				if(x[i]!='a')
					if(x[i]=='b')
					{
						if(fl==1)
							fl=-1,a2=i;
						else if(fl==-1)
						{
							fl=0;
							break;
						}
					}
					else
					{
						fl=0;
						break;
					}
				else if(y[i]!='a')
					if(y[i]=='b')
					{
						if(fl==1)
							fl=-1,b2=i;
						else if(fl==-1)
						{
							fl=0;
							break;
						}
					}
					else
					{
						fl=0;
						break;
					}
		if(fl==-1&&f==-1)
		{
			for(int j=1;j<=n;j++)
				if(d[i]==a2-b2)
					s++;
			cout<<s<<'\n';
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			suc=0;
			for(int k=0;k<lx;k++)
			{
				if(suc==e[j].l&&x[k]!=y[k])
				{
					suc=0;
					break;
				}
				if(x[k]!=y[k]&&x[k]!=e[j].a[suc])
				{
					suc=0;
					break;
				}
				if(x[k]==e[j].a[suc]&&y[k]==e[j].b[suc])
					suc++;
				else if(suc<e[j].l&&suc>0&&(e[j].a[suc]!=x[k]||y[k]!=e[j].b[suc]))
				{
					suc=0;
					break;
				}
			}
			if(suc==e[j].l)
				s++;
		}
		cout<<s<<'\n';
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

3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 2
xabcx xadex
abc ade
bc de
aa bb
xabcx xadex
aaaa bbbb

3 2
aba baa
aaba abba
aaba abaa
aabaa abaaa
aaaba aabaa
*/