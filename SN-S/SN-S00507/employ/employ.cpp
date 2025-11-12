#include<bits/stdc++.h>
using namespace std;
long long n,m,z[100010];
string s;
unsigned long long sum=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m ;
	cin >> s ;
	for(int i=1;i<=n;i++) cin >> z[i] ;
	for(int i=n;i>0;i--)
	{
		sum*=i;
		sum%=998244353;
	}
	cout << sum ;
	return 0;
}
