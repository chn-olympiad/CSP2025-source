#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[3]<a[1]+a[2]){
			cout<<1<<endl;
		}
	}else{
		cout<<0<<endl;
	}
	return 0;
}
