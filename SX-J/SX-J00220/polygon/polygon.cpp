#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","r",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if(n<3){
    	cout<<0;
	}else if(n==3){
		if(a[1]+a[2]>a[3]){
        cout<<1;
		}else{
		cout<<0;
		}
	}
	return 0;
}