#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10]={},n;
	 cin>>n;
	 for(int i=0;i<n;i++){
	 	cin>>a[i];
	 }sort(a,a+n);
	 if(n<3 or a[0]+a[1]<=a[2]){
	 	cout<<0;
	 }else{
	 	cout<<1;
	 }
}
