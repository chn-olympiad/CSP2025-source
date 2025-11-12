#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string s[200010][2],t[200010][2];
string f;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)
		cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=q;i++)
	{
		ans=0;
		for(int j=0;j<t[i][0].size();j++)
		{
			for(int g=1;g<=n;g++)
			{
				int w=0;
				for(int h=j;h<j+s[g][0].size();h++)
					if(t[i][0][h]!=s[g][0][h-j])w=1;
				if(w)continue;
				if(t[i][0].size()-s[g][0].size()+s[g][1].size()!=t[i][1].size())continue;
				for(int h=0;h<j;h++)
					if(t[i][0][h]!=t[i][1][h])w=1;
				for(int h=0;h<s[g][1].size();h++)
					if(s[g][1][h]!=t[i][1][j+h])w=1;
				for(int h=j+s[g][0].size();h<t[i][0].size();h++)
				{
					if(t[i][0][h]!=t[i][1][s[g][1].size()+h-s[g][0].size()])w=1;
				}
				if(w)continue;
				ans++;
			}
			
		}
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}






















