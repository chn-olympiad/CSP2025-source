#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans=(ans%998244353*i)%998244353;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 