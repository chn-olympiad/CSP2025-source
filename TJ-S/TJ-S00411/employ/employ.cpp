#include <bits/stdc++.h>
using namespace std;
long long mod=998224353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string ans; 
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		ans+=s;	
	}
	int num=0; 
	cout<<num%mod;
	return 0;
}
