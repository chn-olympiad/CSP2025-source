#include <bits/stdc++.h>
using namespace std;
long long n,k,a[10005];
int main(){
	cin>>n>>k;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]!=1){
			flag++;
		}
	} 
	if(k==0 && flag==0){
		cout<<n; 
	}
	 
	return 0;
}
