#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],t;
	sort(a+1,a+n*m+1,greater<int>());
	int l=1,r=n*m;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x) {
			t=mid;
			break;
		} 
		else if(a[mid]>x){
			l=mid+1;
		}else if(a[mid]<x){
			r=mid-1;
		}
	}
	int p=t/n;
	if(t%n!=0) p++;
	cout<<p<<' ';
	if(p%2){
		if(t%n==0) cout<<n<<' ';
		else cout<<t%n<<' ';
	}else{
		if(t%n==0) cout<<1<<' ';
		else cout<<n-(t%n)+1;
	}
	return 0;
}
