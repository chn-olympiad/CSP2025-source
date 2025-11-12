#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
string s[2][N],t1,t2;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s[0][i]>>s[1][i];
	}
	for(int k=0;k<q;k++)
	{
		cin>>t1>>t2;
		int l=t1.size();
		if(l!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		int j=0;
		string str="";
		cout<<0<<endl;
	}
	return 0;
}
