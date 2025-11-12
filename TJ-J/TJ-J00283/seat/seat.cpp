#include<bits/stdc++.h>
using namespace std;
int n,m,ans,xb;
int a[1005];
bool cmp(int aa,int bb) {
	return aa>bb;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sz=n*m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+sz+1,cmp);
//	for(int i=1; i<=n*m; i++) {
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
//	int cnt=1;
	for(int i=1; i<=n*m; i++) {
		if(a[i]==ans) {
			xb=i;
			break;
		}
	}
//	cout<<xb<<endl;
	int l=xb/n;//0l shuzhedijilie
	int h=xb%n;//hengzhedijihang
	if(h!=0)l++;
	if(h==0){
		if(l%2==0)h=1;
		else h=n;
	}else{
		if(l%2==0)h=n-h+1;
	}
	cout<<l<<' '<<h;
	return 0;
}
