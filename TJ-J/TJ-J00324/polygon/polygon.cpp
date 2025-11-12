#include <bits/stdc++.h>
using namespace std;
const int MAX=5005;
int a[MAX],sum,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=-1;
	for(int i=3;i<=n;i++){
		sum+=a[i];
		for(int j=1;j<=n;j++){
			maxx=max(a[j],a[j-1]);
		}
		if(sum>maxx*2){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
