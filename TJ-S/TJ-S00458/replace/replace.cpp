#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("replace3.in","r",stdin);
	freopen("replace3.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m; 
	map<string,string>mp;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	for(int i=1;i<=m;i++)
	{
		int cnt=0;
		string a,b;
		cin>>a>>b;
		string s=a;
		if(mp.count(a)&&mp[a]==b)cnt++;
		map<string,string> :: iterator it;
		for(it=mp.begin();it!=mp.end();it++)
		{
			if(a.find(it->first)!=-1)
			{
				//cout<<"ÕÒµ½"<<endl;
				int c=0;
				//cout<<a.find(it->first)<<" "<<a.find(it->first)+it->second.length()<<endl;
				for(int j=a.find(it->first);j<a.find(it->first)+it->second.length();j++)
				{
					a[j]=it->second[c];
					c++;
				}
				//cout<<a<<endl;
				if(a==b)cnt++;
				a=s;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
