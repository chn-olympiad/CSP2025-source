//SN-J00909  臧家乐  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int mod=998244353;
int n;
int a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);		cout.tie(0);
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<n*n*n%mod;
	return 0;
}
