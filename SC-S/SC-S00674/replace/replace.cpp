#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[500005],b[500005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		string u,v;
		cin>>u>>v;
		int l,r;
		int w=u.size();
		for(int i=0;i<w;i++)
		 if(u[i]!=v[i]) 
		 {
		 	l=i;
			break;
		 }
		for(int i=w-1;i>=0;i--)
		 if(u[i]!=v[i]) 
		 {
		 	r=i;
			break;
		 }
		
		for(int j=1;j<=n;j++)
		{
			if(a[j].size()>w||a[j].size()<(r-l+1)) continue;
			for(int k=0;k<=w-a[j].size();k++)
			{
				if(u.substr(k,a[j].size())==a[j]&&v.substr(k,a[j].size())==b[j])
				{
					
					if(k<=l&&k+a[j].size()-1>=r) ans++;
				 }
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}