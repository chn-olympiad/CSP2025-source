#include<bits/stdc++.h>
using namespace std;
long long  n,m,l,r,h,mid,b,a[100086];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	l=1,r=m*n;
	mid=(l+r)/2;
	while(l<r){
		if(a[n*m]==b) {
			mid=n*m;
			break;
		}
		if(a[mid]>b) l=mid;
		if(a[mid]<b) r=mid;
		if(a[mid]==b) break;
		mid=(l+r)/2;
	}
	l=ceil(double(double(mid)/n));
	if(l%2==0){
		h=n-(mid%n)+1;
		if(h>n) h=1;
	}else{
		h=mid%n;
		if(h==0) h=n;
	}
	cout<<l<<" "<<h;
	return 0;
}
