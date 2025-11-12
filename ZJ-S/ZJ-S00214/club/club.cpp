#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[100005],b[100005],c[100005],n;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){cin>>a[i]>>b[i]>>c[i];}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
