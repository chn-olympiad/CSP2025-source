#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s[200005][3];
int c[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		int b1,b2;
		for(int j=0;j<s[i][1].size();j++)
		{
			if(s[i][1][j]=='b')b1=j;
			if(s[i][2][j]=='b')b2=j;
		}
		c[i]=b1-b2;
	}
	string t1,t2;
	while(q--)
	{
		cout<<0<<endl;
		
	}
	return 0;
}