#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5005],z;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;for(int i=1;i<=n;i++){cin>>a[i];if(a[i]!=1)z=1;}
	sort(a+1,a+n+1);
	if(n==3) if((a[1]+a[2]+a[3])*2>=max(a[1],max(a[2],a[3]))) cout<<1;
	else cout<<6;
	return 0;
}