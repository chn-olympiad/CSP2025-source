#include<bits/stdc++.h>

using namespace std;

int n,a[5005]={0};

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		a[n]=a[1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]+a[i+1]<=a[j]){
					cout<<0;
					return 0;
				}
			}
		}
	}
	cout<<1<<endl;
	return 0;
}
