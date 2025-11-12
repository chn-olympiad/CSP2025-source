#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int a[1010];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		sort(a+n,a+n+1);
	}
	for(int i=1;i<=n*m;i++){
		cout<<a[i];
	} 
	return 0;
}
