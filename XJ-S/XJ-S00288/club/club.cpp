#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
int k=1,l=1,s=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin >> t;
	while(t--){
		int ans=-1;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		if(n==2){
			ans=max(ans,a[1]+b[2]);
			ans=max(ans,a[1]+c[2]);
			ans=max(ans,b[1]+a[2]);
			ans=max(ans,b[1]+c[2]);
			ans=max(ans,c[1]+a[2]);
			ans=max(ans,c[1]+b[2]);
			cout << ans << endl;
		}
	}
	return 0;
}
