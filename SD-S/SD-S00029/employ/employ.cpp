#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod=998244353;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
signed main ()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	int res=1;
	for(int i=n;i>=1;i--)
	{
		res*=i;
		res%=mod;
	}
	cout<<res/3<<"\n";
	return 0;
}
