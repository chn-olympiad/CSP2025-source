#include<bits/stdc++.h>
using namespace std;
const int o=998244353;
int n,m,a[5005];
void f(int k,int x,int y,int z)
{
	if(k==n+1)
	{
		if(x>2&&2*z<y)m=(m+1)%o;
		return;
	}
	f(k+1,x,y,z),f(k+1,x+1,a[k]+y,max(a[k],z));
}
int main()
{
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	f(1,0,0,0),cout<<m;
	return 0;
}
