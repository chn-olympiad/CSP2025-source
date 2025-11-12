#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
struct ren{
	int a=0,nb;
}p[100105],p1[100105],p2[100105];
bool us[300205];
bool cmp(ren x,ren y){
	return x.a>y.a;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0,ans1=0;
		for(int i=0;i<n;i++){
			cin>>p[i].a>>p1[i].a>>p2[i].a;
			p[i].nb=p1[i].nb=p2[i].nb=i;
		}
		sort(p,p+n,cmp);
		for(int i=0;i<n/2;i++){
			ans+=p[i].a;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
