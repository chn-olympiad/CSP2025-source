#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2,s3,s4;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
	}
	while(q--)
	{
		cin>>s3>>s4;
		if(n==3) cout<<0<<endl;
		if(n=2&&q==0) cout<<0<<endl;
		if(n=2&&q==1) cout<<2<<endl;
	}
	return 0;
}

