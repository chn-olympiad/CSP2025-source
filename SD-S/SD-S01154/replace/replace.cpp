#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,ans;
string s[200005][2],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0];
		cin>>s[i][1]; 
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>t1;
		cin>>t2;
		for(int i=0;i<t1.size();i++)
		{
			for(int j=1;j<=n;j++)
			{
				string x=t1;
				x=x.replace(i,s[j][1].size(),s[j][1]); 
				if(x==t2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	cout<<endl;
	return 0;
 } 
