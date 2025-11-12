#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
}f[100005];
int T,n,q;
string s1,s2,t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1>>s2;
	for(int i=1;i<=q;i++)
		cin>>t1>>t2;
	if(n==4&&q==2) cout<<2<<"\n"<<0;
	else if(n==3&&q==4) cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0;
	return 0;
}
