//SN-J01168 ¬нич–щ 
#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
bool get[50];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int _mx=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		_mx=max(_mx,a[i]);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>_mx*2) cout << "1";
		else cout << "0";
		return 0;
	}
	int m=pow(2,n);
	int cnt=0;
	for(int i=1;i<=m-1;i++){
		get[1]^=1;
		for(int j=1;j<=n-1;j++){
			int mod=pow(2,j);
			if(i%mod==0) get[j+1]^=1;
		}
		int sum=0,mx=0;
		for(int j=1;j<=n;j++){
			if(get[j]==1){
				sum+=a[j];
				mx=max(a[j],mx);
			}
		}
		if(sum>mx*2) cnt++;
	}
	cout << cnt;
	return 0;
}
