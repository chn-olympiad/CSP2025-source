#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//
	int n,m;
	int a[5010];
	cin>>n
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	m=a[0]+a[1]+a[2];
	if(m<a[0]*2||m<a[1]*2||m<a[2]*2){
		cout<<'0';
	}else{
		cout<<'1';
	}
	return 0;
}
