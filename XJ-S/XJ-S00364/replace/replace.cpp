#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q;
string a[maxn],b[maxn];
string t1[maxn],t2[maxn];
bool pd(string s)
{
	int l=s.size();
	int num=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]!='a'&&s[i]!='b') return 0;
		if(s[i]=='b') num++;
		if(num>1) return 0;
	}
	return 1;
}
vector<pair<int,int>> lB[5000005],rB[5000005];
void solveb()
{
	
	for(int i=1;i<=n;i++)
	{
		int pos1,pos2;
		int l=a[i].size();
		for(int j=0;j<l;j++)
		{
			if(a[i][j]=='b')
			{
				pos1=j;break;
			}
		}
		for(int j=0;j<l;j++)
		{
			if(b[i][j]=='b')
			{
				pos2=j;break;
			}
		}
		if(pos1<pos2) rB[pos2-pos1].push_back(make_pair(pos1-1,l-pos1));
		else lB[pos1-pos2].push_back(make_pair(pos1-1,l-pos1));
	}
	for(int i=1;i<=q;i++)
	{
		if(t1[i].size()!=t2[i].size()) 
		{
			cout<<0<<endl;
			continue;
		}
		int pos1,pos2;
		int l=t1[i].size();
		for(int j=0;j<l;j++)
		{
			if(t1[i][j]=='b')
			{
				pos1=j;break;
			}
		}
		for(int j=0;j<l;j++)
		{
			if(t2[i][j]=='b')
			{
				pos2=j;break;
			}
		}
		int ans=0;
		if(pos1<pos2)
		{
			for(auto j:rB[pos2-pos1])
			{
				if(j.first<=pos1-1&&j.second<=l-pos1) ans++;
			}
		}
		else 
		{
			for(auto j:lB[pos1-pos2])
			{
				if(j.first<=pos1-1&&j.second<=l-pos1) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
bool yy(string a,string b,int l,int r)
{
	for(int pos=l;pos<=r;pos++)
	{
		if(a[pos-l]!=b[pos])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	bool fb=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(fb) fb&=pd(a[i]);
		if(fb) fb&=pd(b[i]);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
		if(fb) fb&=pd(t1[i]);
		if(fb) fb&=pd(t2[i]);
	}
	if(fb) solveb();
	else
	{
		for(int i=1;i<=q;i++)
		{
			if(t1[i].size()!=t2[i].size()) 
			{
				cout<<0<<endl;
				continue;
			}
			int ans=0;
			int l=t1[i].size();
			int posl,posr;
			for(posl=0;posl<l;posl++) if(t1[i][posl]!=t2[i][posl]) break;
			for(posr=l-1;posr>=0;posr--) if(t1[i][posr]!=t2[i][posr]) break;
			for(int ll=0;ll<=posl;ll++)
			{
				for(int rr=posr;rr<l;rr++)
				{
					for(int j=1;j<=n;j++)
					{
						if((int)a[j].size()!=rr-ll+1) continue;
						if(yy(a[j],t1[i],ll,rr)&&yy(b[j],t2[i],ll,rr)) ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
