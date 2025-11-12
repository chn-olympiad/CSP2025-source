#include <bits/stdc++.h>
using namespace std;
int n,k;
int cnt=0;
int a[105];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2 and k==0){
		if(a[0]^+a[0]==0){
			cnt++;
		}
		if(a[1]^+a[1]==0){
			cnt++;
		}
		if(a[0]^+a[1]==0){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
