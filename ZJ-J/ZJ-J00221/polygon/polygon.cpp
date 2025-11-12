#include<bits/stdc++.h>
using namespace std;
const int N=5e3+7;
long long n,a[N],b[N],t=3,ans;
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	t=3;
	while(t<n){
		for(int i=n;i>=t;i--){
			if((b[i]-b[i-t])>a[i]*2) {
				ans+=((i-t+1)*(i-t))/2;
			}
		}
		t++;
	}
	cout<<ans%998244353+2;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
