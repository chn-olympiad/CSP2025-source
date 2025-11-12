#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int t,n,a[N],m,h=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		h*=i;
	}
	cout<<h%998244353;
	return 0;
}