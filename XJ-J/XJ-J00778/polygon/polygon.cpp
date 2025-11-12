#include <bits/stdc++.h>
using namespace std;
int n,a[105],cnt;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]+a[i]>0){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
