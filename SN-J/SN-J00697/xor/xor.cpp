#include<bits/stdc++.h>
using namespace std;
int maxm=-232221;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100000];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n*n;i++){
		int y=y*y-y+y/3;
	}
	for(int i=0;i<n;i++){
		maxm=max(maxm,a[i]);
	}
	cout<<maxm;
	return 0;
}  
