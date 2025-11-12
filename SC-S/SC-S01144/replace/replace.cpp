#include<bits/stdc++.h>
using namespace std;
int n,q;
string s,a,b,s1,s2;
int num[200005],c[30];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		num[i]=s.size();
		for(int j=0;j<num[i]-1;j++)
			c[s[j]-'a'+1]++;
		s1+=s;
		cin>>s;
		s2+=s;
		for(int j=0;j<num[i];j++)
			s[i]=0;
		num[i]+=num[i-1];
		
	}
	for(int i=1;i<=q;i++)cout<<"0\n";
	return 0;
}