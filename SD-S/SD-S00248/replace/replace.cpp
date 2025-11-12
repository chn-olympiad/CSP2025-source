#include <iostream>
#include <cstdio>
using namespace std;
const int N=2e5+10;
int n,q;
string s1[N],s2[N],t1[N],t2[N];
int len[N],u1[N],v1[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		int u,v,l1=s1[i].size(),l2=s2[i].size();
		for(int j=0;j<l1;j++)
		{
			if(s1[i][j]=='b')
			{
				u=j;
			}
		}
		for(int j=0;j<l2;j++)
		{
			if(s2[i][j]=='b')
			{
				v=j;
			}
		}
		u1[i]=u;
		v1[i]=l1-u;
		len[i]=u-v;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
		int u,v,ans=0,l1=t1[i].size(),l2=t2[i].size();
		for(int j=0;j<l1;j++)
		{
			if(t1[i][j]=='b')
			{
				u=j;
			}
		}
		for(int j=0;j<l2;j++)
		{
			if(t2[i][j]=='b')
			{
				v=j;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(len[j]==u-v&&u>=u1[j]&&l1-u>=v1[j])
			{
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
