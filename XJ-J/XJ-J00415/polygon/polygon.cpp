#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int r;
	cin>>r;
	for(int i=1;i<=r;i++){
		cin>>a[i];
	}
	cout<<a[r/2];
	return 0;
} 
