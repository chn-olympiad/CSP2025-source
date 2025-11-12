#include<bits/stdc++.h>
#define mn 511111
using namespace std;
int n,k,a[511111],p[511111],ans;
int main() {
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k,p[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i],p[i]=p[i-1]^a[i];
	int pt=0;
	for(int i=1;i<=n;i++) {
		while((p[i]^p[pt])>k && pt<i-1) pt++;
		//cout<<pt<<" "<<i<<" "<<(p[i]^p[pt])<<" "<<ans<<endl;
		if((p[i]^p[pt])==k) ans++,pt=i;
		//cout<<pt<<" "<<i<<" "<<(p[i]^p[pt])<<" "<<ans<<endl;
		//cout<<endl;
	}
	cout<<ans<<endl;
	fclose(stdin),fclose(stdout);
}