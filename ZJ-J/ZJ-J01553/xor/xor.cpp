#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n,k;
bool check(int m){
	if(m>n||m<1){
		return false;
	}
	int ret=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt^=a[i];
		if(cnt==k){
			ret++;
			cnt=0;
		}
	}
	return ret>=m;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=n,ret=1e9;
	while(l<=r){
		int mid=r-(r-l)/2;
		if(check(mid)){
			l=mid+1;
			ret=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ret;
	return 0;
}
