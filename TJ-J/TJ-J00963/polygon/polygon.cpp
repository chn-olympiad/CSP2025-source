#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,a[10];
    cin>>n;
    if(n<3){
    	cout<<0<<endl;
    	return 0;
	}
    if(n==3){
    	cin>>a[1]>>a[2]>>a[3];
    	if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2]){
    		cout<<1;
		}else{
			cout<<0;
		}
	}
    return 0;
}
