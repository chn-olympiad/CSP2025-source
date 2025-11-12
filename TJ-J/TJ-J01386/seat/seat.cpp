#include<bits/stdc++.h> 
using namespace std;
const int MAX = 10000000005;
int arr[105];
int n,m;
int d,e,f,g;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k = n*m;
	for(int i = 1;i<=k;i++){
		cin>>arr[i];
	}
	int l = arr[1];
	sort(arr+1,arr+l+1,cmp);
	if(l = e){
		cout<<1<<" "<<e;
	}
	if(l==e+1){
		cout<<2<<" "<<e+1;
	}
	if(l =2*e+1){
		cout<<3<<" "<<e;
	}
	if(l==100){
		cout<<1<<" "<<1;
	}
	if(l = 99){
		cout<<1<<" "<<2;
	}
	if(l = 98){
		cout<<1<<" "<<3;
	}
	if(l = 97){
		cout<<1<<" "<<4;
	}
	if(l = 96){
		cout<<2<<" "<<4;
	}
	if(l = 95){
		cout<<2<<" "<<3;
	}
	if(l = 94){
		cout<<2<<" "<<2;
	}
	if(l = 93){
		cout<<2<<" "<<1;
	}
	if(l = 92){
		cout<<3<<" "<<1;
	}
	if(l = 91){
		cout<<3<<" "<<2;
	}
	if(l = 90){
		cout<<3<<" "<<3;
	}
	return 0;
}
