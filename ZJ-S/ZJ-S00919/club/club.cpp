#include <bits/stdc++.h>
using namespace std;
int a[10],b[100005],c[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		int ans=0,n;
		cin>>n;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cin>>a[j];
				b[i]=max(b[i],a[j]);
			}
		}
		for (int i=1;i<=n;i++){
			ans+=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
