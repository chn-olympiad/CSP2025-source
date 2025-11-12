/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/

#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
map<string,int> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int i,j;
	for(i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2],mp[s[i][1]] = i;
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int cnt = 0;
		int l = t1.size();
		for(i=0;i<=l;i++)
		{
			for(j=i;j<=l;j++)
			{
				string k = t1.substr(i,j-i+1);
				if(mp[k])
				{
//					cout<<i<<' '<<j<<endl;
					string x;
					if(i==0)
						x = "";
					else
						x = t1.substr(0,i-1);
					string z;
					if(j==l)
						z = "";
					else
						z = t1.substr(j+1,l);
					string nw = x+s[mp[k]][2]+z;
					if(nw==t2)
					{
						cnt++;
//						cout<<i<<' '<<j<<endl;
//						cout<<nw<<endl;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
