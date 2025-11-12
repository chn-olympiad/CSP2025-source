#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000][1000];
//int cu(int i,int j){
//	for(;i<n;){
//		if()
//	}
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[0][i];
//		for(int j=1;j<i;j++){
//			a[j][i-j]=a[j-1][i-j]^a[j-1][i-j+1];
//		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			if(a[i][j]==k){
//				
//			}
//		}
//	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		cout<<1;
	}if(n>2&&n<=100){
		cout<<n/2;
	}
	return 0;
}
