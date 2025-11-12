#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int def(int x){
	if(x==0){
		return 0;
	}else if(x==1){
		return 1;
	}else{
		int k=1;
		for(int i=0;i<x-1;i++){
			k*=3;
		}
		return def(x-1)+def(x-2)+k+1;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxm=-1e6;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>=maxm){
			maxm=a[i];
		}
	}
	if(n==3){
		if((a[0]+a[1]+a[2])>2*maxm){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(maxm==1){
		cout<<def(n-2);
	}	
	//int l,r;
	//for(int i=0;i<n-2;i++){
		//int l=2
		//for(int j=i+1;j<n-1;j++){
			//for(int k=j+1;k<n;k++){
			//	if()
			//}
		//}
	//}
	return 0;
}
