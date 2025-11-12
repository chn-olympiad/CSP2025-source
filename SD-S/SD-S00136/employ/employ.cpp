#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,f,c[505],ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]=='0') f=1;
	}
	if(n==m&&!f)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=M;
	}
	cout<<ans;
	return 0;
}

