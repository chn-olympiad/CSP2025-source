#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
map<string,string> m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		m[s1]=s2;
	}
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size(),ans=0;
		for(int i=0;i<len;i++)
		{
			for(int j=i;j<len;j++)
			{
				string res="";
				for(int k=i;k<=j;k++) res+=s1[i];
				if(m.count(res)) 
				{
					bool flag=1;
					for(int k=0;k<len;k++)
					{
						if(k>=i&&k<=j)
						{
							string now=m[res];
							while(k<=j)
							{
								if(now[k]!=s2[k])
								{
									flag=0;
									break;
								}
								k++;
							}
						}
						else if(s1[k]!=s2[k])
						{
							flag=0;
							break;
						}
					}
					if(flag) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
