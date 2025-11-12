#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int a[n+5][4];
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		sort(a,a+n+1);
		for(int j=1;j<=n;j++){
			for(int k;k<=3;k++){
				cout<<a[j][k]<<' ';
			}
			cout<<endl;
		}
    }	
return 0;
}
