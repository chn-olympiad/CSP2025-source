#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
map<string,bool> mp; 
int ans=0;
bool bj[N],bj1[N];
void dfs(string a,string b)
{
	if(a==b)
	{
		ans++;
		return ;
	}
	if(mp[a]==1) return ;
	mp[a]=1;
	for(int i=0;i<a.size();i++)
	{
		if(bj1[i]) continue;
		for(int j=1;j<=n;j++)
		{
			if(bj[j]) continue;
			int ls=s1[j].size();
			if(i<a.size()+1-ls) 
			{
				bool flag=0;
				for(int k=i;k<i+ls;k++) 
				{
					if(a[k]!=s1[j][k-i])
					{
						flag=1;
						break;
					}
				}
				if(!flag)
				{
					bj1[i]=1,bj[j]=1;
					string s="";
					for(int k=0;k<i;k++) s+=a[k];
					for(int k=i;k<i+ls;k++) s+=s2[j][k-i];
					for(int k=i+ls;k<a.size();k++) s+=a[k];
					dfs(s,b);
					bj[j]=0,bj1[i]=0;
				}
			}
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--)
	{
		mp.clear(),ans=0;
		string a,b;
		cin>>a>>b;
		dfs(a,b);
		cout<<ans<<endl;
	}
	return 0;
}

