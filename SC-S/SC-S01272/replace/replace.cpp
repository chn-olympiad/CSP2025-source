#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,q;
string s1[200005],s2[200005],t1,t2;
map<pair<string,string>,vector<pair<int,pair<int,int> > > >vis;

signed main(void)
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		int l=-1,r=s1[i].length();
		while(s1[i][l+1]==s2[i][l+1])l++;
		while(s1[i][r-1]==s2[i][r-1])r--;
		string k1,k2;
		for(int j=l+1;j<r;j++)
		{
			k1+=s1[i][j];
			k2+=s2[i][j];
		}
		vis[make_pair(k1,k2)].push_back(make_pair(i,make_pair(l,r)));
	}
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		int l=-1,r=t1.length();
		while(t1[l+1]==t2[l+1])l++;
		while(t1[r-1]==t2[r-1])r--;
		string k1,k2;
		for(int j=l+1;j<r;j++)
		{
			k1+=t1[j];
			k2+=t2[j];
		}
		for(int i=0;i<vis[make_pair(k1,k2)].size();i++)
		{
			int x=vis[make_pair(k1,k2)][i].first,y=vis[make_pair(k1,k2)][i].second.first,z=vis[make_pair(k1,k2)][i].second.second;
			bool flg=true;
			for(int j=0;l-j>=0&&y-j>=0;j++)
			{
				if(t1[l-j]!=s1[x][y-j])
				{
					//cout<<"l:"<<l<<" "<<y<<" "<<j<<endl;
					flg=false;
					break;
				}
			}
			for(int j=0;r+j<t1.length()&&z+j<s1[x].length();j++)
			{
				if(t1[r+j]!=s1[x][z+j])
				{
					//cout<<"r:"<<r<<" "<<z<<" "<<j<<endl;
					flg=false;
					break;
				}
			}
			if(flg)ans++;
		}
		cout<<ans<<endl;
	}
}

/*
5 2
ab acb
abc efb
eeffcc eebbcc
ff bb
eff ebb
ceeffcc ceebbcc
abc acbc
*/
