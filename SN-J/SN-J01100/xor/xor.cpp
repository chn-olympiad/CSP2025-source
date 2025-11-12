#include<bits/stdc++.h>
using namespace std;
int n,k,x,ans,a[500025],cnt=1,sum;
int bj[500025];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]=a[i]^a[i-1];
		for(int j=i-1; !bj[j+1]&&j>=0; j--) {
			if((a[i]^a[j])==k) {
				bj[i]++;
				break;
			}
		}if(bj[i])ans++;
	}
	cout<<ans;
	return 0;
}
