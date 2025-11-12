#include<bits/stdc++.h>
using namespace std;
int num=1;
//int s(int x){
//	if(num>n){
//		return;
//	}
//	num++;
//	for(int j=1;j<=x;j++){
//		if(j^s(n)==k){
//			num
//		}
//	}
//	num++;
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out ","w",stdout);
	int n,nn=0;
	long long k,a[n+5]={0};
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==k){
		nn=1;
	}
	if(a[2]==k){
		nn=1;
	}
	if((a[1]^a[2])==k){
		nn=2;
	}
	cout<<nn;
//	for(int i=1;i<=n;i++){
//		s(n);
//	}
	return 0;
}
//001
//000
//011
