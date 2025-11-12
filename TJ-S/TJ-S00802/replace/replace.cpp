#include <bits/stdc++.h>
using namespace std;
int n,q,con;
string s[100001][2];
string t;
string tt;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	
	while(q--)
	{
		con=0;
		cin>>t;
		string tx=t;
		cin>>tt;

		for(int i=0;i<n;i++)
		{
			t=tx;
			if(t.find(s[i][0])<t.length()&&t.find(s[i][0])>=0)
			{
				string ss=s[i][1];
				
				int c=0;
				int cc=t.find(s[i][0]);
				for(int j=cc;j<min(t.length(),cc+s[i][0].length());j++)
				{
					t[j]=ss[c++];
				}
				
				if(t==tt)
				{
					con++;
				}
			}
		}
		cout<<con<<endl;
	}
	
	return 0;
}
/**
2 1
ab bc
bc cd
abb abc
**/
/**
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
**/ 
