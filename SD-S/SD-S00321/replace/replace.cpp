#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<string,string> >vec;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1[n+1],s2[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		vec.push_back({s1[i],s2[i]});
	}
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++)
		{
			for(int j=i;j<t1.size();j++)
			{
				int flag=1;
				string x;
				for(int k=i;k<=j;k++)
				{
					x=x+s1[k];
				}
				if(vec.first.find(x))
			}
		}
	}
	return 0;
} 
