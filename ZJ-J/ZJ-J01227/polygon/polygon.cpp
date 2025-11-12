#include <iostream>
using namespace std;
int n,a[114514];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a[1]>>a[2]>>a[3];
	if(n>=4){
		cout<<n+n-1;
	} else {
		if(n==3){
			if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3]){
				cout<<1;
			} else {
				cout<<0;
			}
		}
	}
	return 0;
	//666
}