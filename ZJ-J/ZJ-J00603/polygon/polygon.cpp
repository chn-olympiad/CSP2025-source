#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005];
int sum[1000005],cnt;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n==1||n==2) {
		cout<<"0";
	} else if(n==3) {
		sort(a+1,a+n+1);
		if(a[3]*2<a[3]+a[2]+a[1]) {
			cout<<"1";
		} else {
			cout<<"0";
		}
	} else if(n==4) {
		int cnt=0;
	//	123 124 234
		if(a[3]*2<a[3]+a[2]+a[1]) {
			cnt++;
		}
		if(a[4]*2<a[4]+a[2]+a[1]) {
			cnt++;
		}
		if(a[4]*2<a[4]+a[3]+a[2]) {
			cnt++;
		}
		if(a[4]*2<a[4]+a[3]+a[2]+a[1]){
			cnt++;
		}
		cout<<cnt;
	}else if(n==5){
		//123 124 125 234 235 245 345 1234 1235 1245 1345 2345 12345
		if(a[3]*2<a[3]+a[2]+a[1]) {
			cnt++;
		}
		if(a[4]*2<a[4]+a[2]+a[1]) {
			cnt++;
		}
		if(a[5]*2<a[5]+a[2]+a[1]){
			cnt++;
		}
		if(a[5]*2<a[5]+a[2]+a[4]){
			cnt++;
		}
		if(a[4]*2<a[4]+a[3]+a[2]) {
			cnt++;
		}
		if(a[5]*2<a[5]+a[3]+a[2]) {
			cnt++;
		}
		if(a[5]*2<a[5]+a[4]+a[3]) {
			cnt++;
		}
		if(a[4]*2<a[4]+a[3]+a[2]+a[1]){
			cnt++;
		}
		if(a[5]*2<a[5]+a[3]+a[2]+a[1]){
			cnt++;
		}		
		if(a[5]*2<a[5]+a[4]+a[2]+a[1]){
			cnt++;
		}
		if(a[5]*2<a[5]+a[4]+a[3]+a[1]){
			cnt++;
		}
		if(a[5]*2<a[4]+a[3]+a[2]+a[5]){
			cnt++;
		}
		if(a[5]*2<a[5]+a[4]+a[3]+a[2]+a[1]){
			cnt++;
		}
		cout<<cnt;
	}else if(n==6){
		//123 124 125 234 235 245 345 1234 1235 1245 1345 2345 12345
		//           126     236 246 346 456  1236 1246 1256 1346 1356 1456 2346 2356 2456 3456
		if(a[6]*2<a[6]+a[2]+a[1]) {
				cnt++;
		}
		if(a[6]*2<a[6]+a[2]+a[3]) {
			cnt++;
		}if(a[6]*2<a[6]+a[2]+a[4]) {
			cnt++;
		}
		if(a[6]*2<a[6]+a[4]+a[3]) {
			cnt++;
		}
		if(a[6]*2<a[6]+a[5]+a[4]) {
			cnt++;
		}
		if(a[6]*2<a[6]+a[3]+a[2]+a[1]) {
			cnt++;
		}
		if(a[6]*2<a[6]+a[2]+a[1]+a[4]) {
			cnt++;
		}
		if(a[6]*2<a[6]+a[2]+a[1]+a[5]) {
			cnt++;
		}	
		if(a[6]*2<a[6]+a[3]+a[1]+a[4]) {
			cnt++;
		}	
		if(a[6]*2<a[6]+a[2]+a[1]+a[5]) {
			cnt++;
		}	
		if(a[6]*2<a[6]+a[3]+a[1]+a[5]) {
			cnt++;
		}	
		if(a[6]*2<a[6]+a[4]+a[1]+a[5]) {
			cnt++;
		}
		if(a[6]*2<a[6]+a[4]+a[2]+a[3]) {
			cnt++;
		}
		if(a[6]*2<a[6]+a[5]+a[2]+a[3]) {
			cnt++;
		}
		if(a[6]*2<a[6]+a[5]+a[2]+a[4]) {
			cnt++;
		}			
		if(a[6]*2<a[6]+a[5]+a[4]+a[3]) {
			cnt++;
		}		
		if(a[3]*2<a[3]+a[2]+a[1]) {
			cnt++;
		}
		if(a[4]*2<a[4]+a[2]+a[1]) {
			cnt++;
		}
		if(a[5]*2<a[5]+a[2]+a[1]){
			cnt++;
		}
		if(a[5]*2<a[5]+a[2]+a[4]){
			cnt++;
		}
		if(a[4]*2<a[4]+a[3]+a[2]) {
			cnt++;
		}
		if(a[5]*2<a[5]+a[3]+a[2]) {
			cnt++;
		}
		if(a[5]*2<a[5]+a[4]+a[3]) {
			cnt++;
		}
		if(a[4]*2<a[4]+a[3]+a[2]+a[1]){
			cnt++;
		}
		if(a[5]*2<a[5]+a[3]+a[2]+a[1]){
			cnt++;
		}		
		if(a[5]*2<a[5]+a[4]+a[2]+a[1]){
			cnt++;
		}
		if(a[5]*2<a[5]+a[4]+a[3]+a[1]){
			cnt++;
		}
		if(a[5]*2<a[4]+a[3]+a[2]+a[5]){
			cnt++;
		}
		if(a[5]*2<a[5]+a[4]+a[3]+a[2]+a[1]){
			cnt++;
		}
		cout<<cnt;
	}else{
		cnt=n*n;
		cout<<cnt;
	}
	return 0;
}