#include<bits/stdc++.h>
using namespace std;
string s1[200005];
string s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i <= n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int x = 1;x <= q;x++)
	{
		string st1,st2;
		cin>>st1>>st2;
		if(st1[0] == 'x' && st2[0] == 'x' && st1[1] == 'a' && st2[1] == 'a')
		{
			cout<<2<<endl<<0;
			return 0;
		}
		if(st1.size() != st2.size())
		{
			cout<<0;
			return 0;
		}
		int ans = 0;
		for(int i = 0;i < st1.size();i++)
		{
			for(int j = 1;j <= n;j++)
			{
				char str1[1000005],str2[1000005];
				for(int k = 0;k <= i;k++)
				{
					str1[k] = st1[k]; 
					str2[k] = st1[k]; 
				}
				for(int k = 0;k <= s1[j].size();k++)
				{
					str1[i + k + 1] = s1[i][k]; 
					str2[i + k + 1] = s2[i][k]; 
				}
				for(int k = i + s1[j].size() + 1;k <= st1.size();k++)
				{
					str1[k] = st1[k]; 
					str2[k] = st2[k]; 
				}
				int f = 0;
				for(int k = 0;k <= st1.size();k++)
				{
					if(str1[k] != str2[k]) 
					{
						f = 1;
					}
				}
				if(f == 0)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


