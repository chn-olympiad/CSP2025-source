#include<bits/stdc++.h>
using namespace std;
long long n,m,arr[637],ans[637],r;
long long sh,ys;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;

	for(int i=1; i<=n*m; i++) {
		cin>>arr[i];
		if(i==1) {
			r=arr[i];
		}
	}
	sort(arr+1,arr+n*m+1);
	long long ans=0;

	for(int i=n*m; i>=1; i--) {
		ans++;
		if(arr[i]==r) {

			break;
		}
	}
	sh=ans/n+1;
	ys=ans%n;
//	cout<<"ceshi:"<<sh<<' '<<ys<<endl;
	if(ys==0) {
		sh-=1;
		if(sh%2==1) cout<<sh<<' '<<n;
		else cout<<sh<<' '<<1;
	} else {
		if(sh%2==1)cout<<sh<<' '<<ys; 
		else cout<<sh<<' '<<n-ys+1;
	}
}

