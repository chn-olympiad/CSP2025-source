#include<bits/stdc++.h>
using namespace std;
const int maxn=200;
string s[maxn][2];
string cut(string ss,int s,int l)
{
	string a="";
	for(int i=0;i<l;i++)
	{
		a+=ss[s];
		s++;
	}
}
int n,q;
int main()
{
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>s[i][0]>>s[i][1];
	while(q--)
	{
		string t1,t2,x1="",x2;
		int ans=0;
		cin>>t1>>t2;
		for(int i=0;i<t1.length();i++)
		{
			for(int j=1;j<t1.length()-i;j++)
			{
				x1=cut(t1,i,j),x2=cut(t2,i,j);
				for(int k=0;k<n;k++)
				{
					if(s[k][0]==x1 and s[k][1]==x2) ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
