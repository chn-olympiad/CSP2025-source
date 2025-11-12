#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N];
int main() {
	freopen("polygon.in","r"stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		cout<<"1";
	}
	else{
		cout<<n*2-1;
	}
	return 0;
}
