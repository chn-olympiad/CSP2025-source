#include<bits/stdc++.h>
using namespace std;
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,p=0;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	  cin>>c[i];
	sort(c+1,c+n+1);
	for(int i=n;i>0;i--)
	{
		if(c[i]>=n) p++;
	}
	cout<<p%998244353<<endl;
	return 0;
} 
