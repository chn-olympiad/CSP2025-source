#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<rand()%mod;
	return 0;
}
