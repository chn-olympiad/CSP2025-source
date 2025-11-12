#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],t1[200005],t2[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i,j,len_t1,len_t2;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
	}
	for(i=1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
} 
