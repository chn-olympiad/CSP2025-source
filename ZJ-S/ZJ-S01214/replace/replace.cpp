#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,M=2e6+1;
int n,q,ans[N],st[N],ed[N];
int nxt[M],bel[M];
string s1[N],s2[N],s[N],t[N];
void kmp(int comp)
{
	vector< pair<char,char> > p;
	int s1s=s1[comp].size();
	for(int i=0;i<s1s;i++)
		p.push_back(make_pair(s1[comp][i],s2[comp][i]));
	for(int o=1;o<=q;o++)
	{
		p.push_back(make_pair('.','.'));
		int ss=s[o].size();
		for(int i=0;i<ss;i++)
		p.push_back(make_pair(s[o][i],t[o][i]));
	}
	int ps=p.size();
	//for(int i=0;i<ps;i++)
	//cout<<"["<<p[i].first<<","<<p[i].second<<']'<<" ";
	//cout<<'\n';
	//for(int i=0;i<ps;i++)
	//cout<<"[ "<<bel[i]<<" ] ";
	//cout<<'\n';
	nxt[0]=-1;
	for(int i=1;i<ps;i++)
	{
		int x=nxt[i-1];
		while(x!=-1&&p[i]!=p[x+1])x=nxt[x];
		if(p[i]==p[x+1])x++;
		nxt[i]=x;
	}
	for(int i=s1[comp].size()+1;i<ps;i++)
	{
		if(nxt[i]>=s1s-1)
			ans[bel[i]]++;
	}
	for(int i=0;i<ps;i++)nxt[i]=0;
	return;
}
void fre()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
int main()
{
	fre();
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)
	{
		cin>>s[i]>>t[i];
		while(s[i].size()<t[i].size())s[i]+='>';
		while(s[i].size()>t[i].size())t[i]+='>';
		st[i]=s[i].size()-1,ed[i]=0;
		int ss=s[i].size();
		for(int j=0;j<ss;j++)if(s[i][j]!=t[i][j])ed[i]=j;
		for(int j=ss-1;j>=0;j--)if(s[i][j]!=t[i][j])st[i]=j;
	}
	
	for(int k=1;k<=n;k++)
	{
		memset(bel,0,sizeof(bel));
		int pos=0;
		for(int i=1;i<=q;i++)
		{
			if((int)s1[k].size()>=ed[i]-st[i]+1&&s[i].size()==t[i].size())
			{
				int S=ed[i]+pos+1+s1[k].size();
				int T=st[i]+pos+s1[k].size()*2;
				T=min(T,(int)s[i].size()-1+1+pos+(int)s1[k].size());
				for(int j=S;j<=T;j++)bel[j]=i;
			}
			pos+=s[i].size()+1;
		}
		kmp(k);
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
}
