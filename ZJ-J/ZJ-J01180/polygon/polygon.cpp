#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,a[5005],b[505][505]={0};
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	if(2*(max(max(a[0],a[1]),a[2]))<(a[0]+a[1]+a[2])){
		cout<<1;
	}else{
		cout<<0;
	}
} 
