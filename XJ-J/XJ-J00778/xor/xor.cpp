#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[105],max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=m){
			if(a[i]>max){
				max=a[i];
			}
		} 
	}
	cout<<max;
	return 0;
}
