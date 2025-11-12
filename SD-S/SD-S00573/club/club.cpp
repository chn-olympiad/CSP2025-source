#include<bits/stdc++.h>
using namespace std;
int t,n,l1[100001],l2[100001],l3[100001],a,b,ans;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>l1[i]>>l2[i]>>l3[i];
			a=max(l1[i],l2[i]);
			b=max(l3[i],a);
			ans+=b;
		}
		cout<<ans<<endl;
	}
	return 0;
}

