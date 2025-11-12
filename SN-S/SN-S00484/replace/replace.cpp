#include<bits/stdc++.h>
using namespace std;
int n,q,l[5000005],r[5000005],f1,f2;
string s1,s2;
int main()
{
	freopen("replace3.in ","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		for(int j=0;j<s1.length();j++)
		{
			if(s1[i]=='b') f1=j;
			if(s2[i]=='b') f2=j;
		}
			if(f1-f2>0) l[abs(f1-f2)]++;
			else r[abs(f1-f2)]++;
	}
	
	for(int z=1;z<=q;z++)
	{
		cin>>s1>>s2;
			for(int i=0;i<s1.length();i++)
	{
		if(s1[i]=='b') f1=i;
		if(s2[i]=='b') f2=i;
	}
	if(f1-f2>0) cout<<l[f1-f2]<<endl;
	else cout<<r[f2-f1]<<endl;
	}

	return 0;
}
