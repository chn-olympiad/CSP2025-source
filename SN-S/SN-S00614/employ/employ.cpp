#include<bits/stdc++.h>
using namespace std;
int c(int a){
	int cnt=1;
	for(;a!=0;a--){
		cnt*=a;
	}
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>n>>m;
	if(n==m){
		cout<<c(n);
	}
	else {
		cout<<0;
	}
	return 0;
}
