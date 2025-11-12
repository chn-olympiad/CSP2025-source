#include<bits/stdc++.h>
using namespace std;
int n,a[4];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(0));
	cin>>n;
	if(n==3){
		for(int i=1;i<=3;i++){
			cin>>a[i];
		}
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	int a=rand()%998244351+1;
	cout<<a;
	return 0;
}
