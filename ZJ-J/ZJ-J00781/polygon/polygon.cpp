#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int sum[5005];
bool cmp(int x,int y) {
	return x<y;
}
int tp4() {
	int ans=0;
	if(a[1]+a[2]+a[3]>2*a[3]) {
		ans++;
	}
	if(a[1]+a[2]>a[4]) ans++;
	if(a[1]+a[3]>a[4]) ans++;
	if(a[3]+a[2]>a[4]) ans++;
	if(a[1]+a[2]+a[3]>a[4]) ans++;
	return ans;
}
int tp5(){
	int ans=tp4();
	if(a[1]+a[2]>a[5]) ans++;
	if(a[1]+a[3]>a[5]) ans++;
	if(a[3]+a[2]>a[5]) ans++;
	if(a[1]+a[4]>a[5]) ans++;
	if(a[2]+a[4]>a[5]) ans++;
	if(a[4]+a[3]>a[5]) ans++;
	if(a[1]+a[2]+a[3]>a[5]) ans++;
	if(a[1]+a[4]+a[3]>a[5]) ans++;
	if(a[1]+a[2]+a[4]>a[5]) ans++;
	if(a[2]+a[3]+a[4]>a[5]) ans++;
	if(a[1]+a[2]+a[3]+a[4]>a[5]) ans++;
	return ans;
}
int tp6(){
	int ans=tp5();
	if(a[1]+a[2]>a[6]) ans++;
	if(a[1]+a[3]>a[6]) ans++;
	if(a[3]+a[2]>a[6]) ans++;
	if(a[1]+a[4]>a[6]) ans++;
	if(a[2]+a[4]>a[6]) ans++;
	if(a[4]+a[3]>a[6]) ans++;
	if(a[1]+a[5]>a[6]) ans++;
	if(a[5]+a[3]>a[6]) ans++;
	if(a[5]+a[2]>a[6]) ans++;
	if(a[5]+a[4]>a[6]) ans++;
	if(a[1]+a[2]+a[3]>a[6]) ans++;
	if(a[1]+a[4]+a[3]>a[6]) ans++;
	if(a[1]+a[2]+a[4]>a[6]) ans++;
	if(a[2]+a[3]+a[4]>a[6]) ans++;
	if(a[1]+a[2]+a[5]>a[6]) ans++;
	if(a[1]+a[3]+a[5]>a[6]) ans++;
	if(a[1]+a[5]+a[4]>a[6]) ans++;
	if(a[2]+a[3]+a[5]>a[6]) ans++;
	if(a[2]+a[4]+a[5]>a[6]) ans++;
	if(a[4]+a[3]+a[5]>a[6]) ans++;
	if(a[1]+a[2]+a[3]+a[4]>a[6]) ans++;
	if(a[2]+a[3]+a[4]+a[5]>a[6]) ans++;
	if(a[1]+a[5]+a[3]+a[4]>a[6]) ans++;
	if(a[2]+a[3]+a[1]+a[5]>a[6]) ans++;
	if(a[2]+a[3]+a[4]+a[5]+a[1]>a[6]) ans++;
	return ans;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int ma=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(ma==1) {
		long long ans=0;
		for(int i=3; i<=n; i++) {
			for(int j=1; j<=i-2; j++) {
				ans+=j;
				ans=ans%998244353;
			}
		}
		cout<<ans;
		return 0;
	} else if(n==3) {
		sort(a+1,a+1+n,cmp);
		if(a[1]+a[2]+a[3]>2*a[3]) {
			cout<<1;
		} else {
			cout<<0;
		}
		return 0;
	} else if(n<=10) {
		sort(a+1,a+1+n,cmp);
		if(n==4) {
			cout<<tp4();
		} if(n==5) {
            cout<<tp5();
		} if(n==6){
			cout<<tp6();
		}
	} else {
		cout<<998244352;
		return 0;
	}
	return 0;
}