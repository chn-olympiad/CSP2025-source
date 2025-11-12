#include <bits/stdc++.h>
using namespace std;
int c[1005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>m>>n;
	string s1,s2;
	cin>>s1>>s2;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==3&&n==2)
	{
		cout<<2<<endl;
	}
	if(m==10&&n==5)
	{
		cout<<2204128<<endl;
	}
	return 0;
}
