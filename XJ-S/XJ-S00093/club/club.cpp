#include<bits/stdc++.h>
using namespace std;
int t,n,a[3],b[3],ans,maxx,id;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1; j<=t; j++) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[1]>>a[2]>>a[3];
			ans+=max(a[1],max(a[2],a[3]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
