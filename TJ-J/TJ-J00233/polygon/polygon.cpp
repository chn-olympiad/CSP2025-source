
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	long long n,m=0;
	int a[110011];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	m=a[0]+a[1];
	if(m>=a[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
