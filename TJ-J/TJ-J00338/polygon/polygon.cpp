#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<4){
		int maxx=-1;
		maxx=max(maxx,a[1]);
		maxx=max(maxx,a[2]);
		maxx=max(maxx,a[3]);
		maxx*=2;
		if(a[1]+a[2]+a[3]>maxx){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
}
