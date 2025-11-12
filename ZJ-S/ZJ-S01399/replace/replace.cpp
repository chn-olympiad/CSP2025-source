#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int len,n,ans,q;
string st,ed,u,v;
map<string,string>b;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v;
		b[u]=v;
	}
	while(q--)
	{
		ans=0;
		cin>>st>>ed;
		if(st.size()!=ed.size())
		{
			cout<<0<<endl;
			continue;
		}
		len=st.size();
		for(int i=0;i<len;i++)
		{
			
			for(int j=len-1;j>=i;j--)
			{
				if(b[st.substr(i,j-i+1)]==ed.substr(i,j-i+1))ans++;
				if(st[j]!=ed[j])break;
			}
			if(st[i]!=ed[i])break;
		}
		cout<<ans<<endl;
	}
	return 0;
}

