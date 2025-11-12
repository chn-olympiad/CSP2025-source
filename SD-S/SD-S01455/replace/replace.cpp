#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
string s[114514][3]; 
int n,m;
signed main()
{ 	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i][0]>>s[i][1];
	while(m--)
	{
		int ans=0;
		string a,b;
		cin>>a>>b;
		string x="";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<a.size();j++)
			{
				int k=0;
				while(a[j+k]==s[i][0][k]&&k<s[i][0].size()&&j+k<a.size()) k++;
				//cout<<"k:"<<k<<"j:"<<j<<endl;
				if(k==s[i][0].size())
				{
					string temp=a;
					for(k=0;k<s[i][0].size();k++) a[j+k]=s[i][1][k];
					//cout<<a<<endl;
					if(a==b) ans++;
					a=temp;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
