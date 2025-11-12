#include<iostream>
#include<cstdio>
using namespace std;
int a[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool a1=1,a01=1,a0=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>1) {
			a1=0;
			a01=0;
		}
		if(a[i]==0) {
			a1=0;
		}
		if(a[i]==1) {
			a0=0;
		}
	}
	if(a1) {
		cout<<n/2;
		return 0;
	}
	if(a01) {
		int cnt1=0;
		for(int i=1; i<=n; i++) {
			if(a[i]==1) {
				cnt1++;
			}
		}
		if(k==1) {
			cout<<cnt1;
		} else {
			int cnt11=n-cnt1;
			for(int i=1; i<=n-1; i++) {
				if(a[i]==1&&a[i+1]==1) {
					i+=2;
					cnt11++;
				}
			}
			cout<<cnt11;
		}
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
	    if(a[i]^a[i+1]==k){
			cnt++;
			i+=1;
		}
		else if(a[i+1]^a[i+2]==k){
			i+=2;
			cnt++;
		}
		else{
			a[i+1]=a[i]^a[i+1];
		}
	}
	cout<<cnt;
	return 0;
}
