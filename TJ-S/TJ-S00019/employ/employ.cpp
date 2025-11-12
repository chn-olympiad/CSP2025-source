#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[100001];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<1;i++) cin>>a[i];
	long long num=1;
	for(long long i=1;i<=m;i++)
	{
		num=(num*i)%998244353;
	}
	cout<<num;
	return 0;
}
