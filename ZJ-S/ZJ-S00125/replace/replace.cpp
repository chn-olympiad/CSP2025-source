#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string> s[100001];
map<string ,string > ma;
map<string,bool >ma2;
string cut(int l,int r,string k)
{
	string s;
	for(int i=l;i<=r;i++)
		s.push_back(k[i]);
	return s;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n;cin>>q;
	for(int i=1;i<=n;i++)
	{
		getchar();
		cin>>s[i].first>>s[i].second;
		ma[s[i].first]=s[i].second;
		ma2[s[i].first]=1;
	}
//	cout<<ma2[s[1].first]<<"\n";
//	cout<<s[1].first;
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=0;i<t1.size();i++)
		{
			for(int j=i;j<t1.size();j++)
			{
			//	cout<<cut(i,j,t1)<<"\n";
				if(ma2[cut(i,j,t1)]==1)
				{
				//	cout<<"1\n";
					string temp1=cut(i,j,t1),temp2=t1;
					int k=i;
					for(int k=0;k<ma[cut(i,j,t1)].size();k++)
					{
						temp2[k+i]=ma[cut(i,j,t1)][k];
					}
					if(temp2==t2)
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
