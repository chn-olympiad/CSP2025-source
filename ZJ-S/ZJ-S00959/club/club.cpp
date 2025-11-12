#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
	ll x,y,z,d;
}a[100005];
vector<node>v1,v2,v3;
bool cmp(node a,node b) {return a.d>b.d;}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		v1.clear();
		v2.clear();
		v3.clear();
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		ll cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++) {
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) cnt1++,a[i].d=min(a[i].x-a[i].y,a[i].x-a[i].z),v1.push_back(a[i]);
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) cnt2++,a[i].d=min(a[i].y-a[i].x,a[i].y-a[i].z),v2.push_back(a[i]);
			else cnt3++,a[i].d=min(a[i].z-a[i].y,a[i].z-a[i].x),v3.push_back(a[i]);
		}
		sort(v1.begin(),v1.end(),cmp);
		sort(v2.begin(),v2.end(),cmp);
		sort(v3.begin(),v3.end(),cmp);
		ll ans=0;
		for(int i=0;i<v1.size();i++) ans+=v1[i].x;
		for(int i=0;i<v2.size();i++) ans+=v2[i].y;
		for(int i=0;i<v3.size();i++) ans+=v3[i].z;
		if(cnt1>n/2) for(int i=v1.size()-1;i>=n/2;i--) ans-=v1[i].d;
		if(cnt2>n/2) for(int i=v2.size()-1;i>=n/2;i--) ans-=v2[i].d;
		if(cnt3>n/2) for(int i=v3.size()-1;i>=n/2;i--) ans-=v3[i].d;
		cout<<ans<<endl;
	}
	return 0;
}
