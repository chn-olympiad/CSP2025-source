#include<bits/stdc++.h>
using namespace std;
bool cmp(int o,int p){
	return o>p;
}
int a[1000001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n==2){
			cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6];
			int big=a[1]+a[5];
			if(a[1]+a[6]>=big){
				big=a[1]+a[6];
			}
			if(a[2]+a[4]>=big){
				big=a[2]+a[4];
			}
			if(a[2]+a[5]>=big){
				big=a[2]+a[6];
			}
			if(a[3]+a[4]>=big){
				big=a[3]+a[4];
			}
			if(a[3]+a[5]>=big){
				big=a[3]+a[5];
			}
			cout<<big<<"\n";
		}
		else{
			for(int i=1;i<=n;i++){
				int h,j;
				cin>>a[i]>>h>>j;
				sort(a+1,a+n+1,cmp);
			}
			cout<<a[1]<<"\n";
		}
	}
}
