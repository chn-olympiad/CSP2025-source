#include<iostream>
#define int long long 
using namespace std;

const int N=505,mod=998244353;

int n,m;
string s;
int a[N],c[N];

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	c[1]=1;
	for(int i=2;i<=n;i++)
		c[i]=c[i-1]*i%mod;
	cout<<c[n]<<endl;
	return 0;
 } 
