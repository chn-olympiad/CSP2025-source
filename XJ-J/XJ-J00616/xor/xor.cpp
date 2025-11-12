#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,k;
	cin>>n>>k;
	int a[n],s[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<k;j++){
			if(a[i]<k){
				s[j]++;
			}
		}
	}
	for(int i=k;i>=0;i--){
		if(a[i]!=0){
		cout<<s[i];
		return 0;
		}
	}
	return 0;
}
