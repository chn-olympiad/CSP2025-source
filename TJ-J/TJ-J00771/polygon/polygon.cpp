#include <bits/stdc++.h>
using namespace std;
int max_sum(int a[],int n){
	int max_ = a[1];
	int sum = 0;
	for(int i = 1;i<n;i++){
		sum+=a[i];
		if(a[i]>max_){
			max_ = a[i];
		}
	}
	return max_,sum;
}
int jump(int a[],int x,int n){
	int b[n] = {};
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(i != x){
			cnt++;
		}
		b[cnt] = a[i];
	}
	return b[n];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n] ={};
	long long cnt = 0;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
//	for(int i = 0;i<n;i++){
//		for(int j = i;j<n;j++){
//			int x,y = max_sum(jump(a,i,n),n);
//			if(x<2*y){
//			cnt++;
//			}
//		}
//	}
//	cout<<cnt%988244353<<endl;
}
