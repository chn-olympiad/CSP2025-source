#include<bits/stdc++.h>
using namespace std;
int n,s=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) s=s*i%998244353;
	cout<<s;
	return 0;
}
