#include<bits/stdc++.h>
using namespace std;

int n,q;
string str[200100][5];
 
int main()
{
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	
	for(int i=1;i<=n;++i)cin>>str[i][1]>>str[i][2];
	
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		int ans=0;
		int len=a.length();
		if(len!=b.length())
		{
			cout<<0<<'\n';
			continue;
		}
		
		int frt,tal;
		
		for(int i=0;i<len;++i)if(a[i]!=b[i]){frt=i;break;}
		for(int i=len-1;len>=0;--i)if(a[i]!=b[i]){tal=i;break;}
		for(int i=0;i<len;++i)
		{
			for(int j=i;j<len;++j)
			{
				if(frt<i||tal>j)continue;
				for(int k=1;k<=n;++k)
				{
					if(str[k][1].length()!=j-i+1)continue;
					bool flag=1;
					for(int o=i;o<=j;++o)
					{
						if(a[o]!=str[k][1][o-i]||b[o]!=str[k][2][o-i])flag=0;
					}
					if(flag)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
} 
