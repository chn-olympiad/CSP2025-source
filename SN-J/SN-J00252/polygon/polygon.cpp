#include<bits/stdc++.h>
using namespace std;
long long a[5001],n;
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		for(int j=1;j<=2;j++){
		for(int k=j+1;k<=3;k++){
			if(a[j]<a[k]){
				swap(a[j],a[k]);
			}
		}
	}
	if(a[2]+a[3]>a[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
