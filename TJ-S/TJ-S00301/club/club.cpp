#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
bool cmp(int x,int y) {return x>y;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n,a1[N],a2[N],a3[N];
		long long ans=0;
		cin>>n;
		int cnt=n/2;
		for(int i=1;i<=n;i++) cin>>a1[i]>>a2[i]>>a3[i];
		sort(a1+1,a1+n+1,cmp);
		sort(a2+1,a2+n+1,cmp);
		sort(a3+1,a3+n+1,cmp);
		for(int i=1;i<=cnt;i++) ans+=(a1[i]+a2[i]+a3[i]);
		cout<<ans<<"\n";
	}
	return 0;
}
