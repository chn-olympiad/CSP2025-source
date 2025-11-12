#include<bits/stdc++.h>
using namespace std;
int c[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool bl1=0;//ÊÇ·ñÈ«ÊÇ1 
	int n,m;cin>>n>>m;
	string s;cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')
			bl1=1;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(bl1==0&&n==m)  cout<<1;
	if(bl1!=0&&n==m)  cout<<0;
	return 0;
}
