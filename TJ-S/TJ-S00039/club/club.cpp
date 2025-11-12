#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,a[200005],b[200005],c[200005],ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		if(n == 2){
			int a1 = a[1] + b[2];
			int a2 = a[1] + c[2];
			int a3 = b[1] + a[2];
			int a4 = b[1] + c[2];
			int a5 = c[1] + a[2];
			int a6 = c[1] + b[2];
			a1 = max(a1,a2);
			a1 = max(a1,a3);
			a1 = max(a1,a4);
			a1 = max(a1,a5);
			ans = max(a1,a6);
			cout<<ans<<endl;
			continue;
		}
		sort(a+1,a+n+1);
		for(int j=1;j<=n/2;j++){
			ans += b[j];
		}
		for(int j=n/2;j<=n;j++){
			ans += a[j];
		}
		cout<<ans<<endl;
	}
	return 0;
}
