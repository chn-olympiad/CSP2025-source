#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=3;i<=n;i++){
		int q=1;
		for(int j=n;j>n-i;j--){
			q*=j;
		}
		int q1=1;
		for(int k=2;k<=i;k++){
			q1*=k;
		}
		sum+=q/q1;
	}
	cout<<sum;
}  
