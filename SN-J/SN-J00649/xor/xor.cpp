//SN-J00649  林靖轩  西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int n,k,ans=0,cnt=0;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	for(int i=1;i<=n;i++)
	{
		if(cnt==0)cnt=a[i];
		else cnt^=a[i];
		if(cnt==k)ans++,cnt=0; 
	}
	cout<<ans;
	return 0;
}
//异或仅两数不同为1 
//4 0
//2 1 0 3

