#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n,a[10005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(a[3]<a[2]+a[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
