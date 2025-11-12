#include<bits/stdc++.h>
using namespace std;
long long int n,m,ans=0;
string s;
long long int c[505] ;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j;
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
		ans+=c[i];
	}
	cout<<ans;
	return 0;
}
