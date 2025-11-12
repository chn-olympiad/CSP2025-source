#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n,a[5005],f[5005],sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3) cout<<0;
	if(n==3){
		sort(a+1,a+n+1);
		for(int i=1;i<=3;i++){
			sum+=a[i];
		}
		if(sum>(a[n]*2)) cout<<1;
		else cout<<0;
	}
	return 0;
}
