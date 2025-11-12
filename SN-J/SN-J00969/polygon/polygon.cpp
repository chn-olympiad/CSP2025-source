#include<bits/stdc++.h>
using namespace std;
long long n,a[10086],c,d;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+4);
	if(a[1]+a[2]+a[3]>a[3]*2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
}
