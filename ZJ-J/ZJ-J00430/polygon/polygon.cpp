#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
long long n,a[maxn];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3)
	{
		int mx=max(a[1],max(a[2],a[3]));
		int mc=a[1]+a[2]+a[3];
		if(mc>mx*2) cout<<"1";
		else cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

