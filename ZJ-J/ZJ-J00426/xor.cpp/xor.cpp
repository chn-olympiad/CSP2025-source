#include<bits/stdc++.h>
using namespace std;
int a[100200];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if((a[i] xor sum)==m){
			ans++;
			sum=0;
		}
		else{
			sum=(a[i] xor sum);
		}
	}
	cout<<ans;
	return 0;
}
