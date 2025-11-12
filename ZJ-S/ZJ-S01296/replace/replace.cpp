#include<bits/stdc++.h>
using namespace std;

int n,q;
string s1[200005],s2[200005],t1,t2;
int ans;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int what=1;what<=q;what++)
	{
		ans=0;
		cin>>t1>>t2;
		
		for(int i=1;i<=n;i++)//替换的二元组(s1[i], s2[i])
		{
			for(int j=0;j<=t1.size()-s1[i].size();j++)//x,z
			{
				string y="";
				for(int k=j;k<=j+s1[i].size()-1;k++)y+=t1[k];
				if(y==s1[i]) 
				{
					string s="";
					for(int k=0;k<j;k++)s+=t1[k];
					s+=s2[i];
					for(int k=j+s1[i].size();k<t1.size();k++)s+=t1[k];
					if(s==t2)ans++;
				}
			}
		}
		cout<<ans<<"\n"; 
	}
	return 0;
}
