#include<bits/stdc++.h>
using namespace std;
int n,k,a[200000];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool zero_being=0;int cnt=0,one_being=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0)
		zero_being=1;
		else one_being++;
	}if(!zero_being){
	if(k==0)cout<<n/2;
	else cout<<n;
	return 0;
	}
	else{
	if(k==0){
	for(int i=0;i<n;i++){
		if(a[i]==0)cnt++;
		else{
			if(i<n-1){
				if(a[i+1]==1){
					i++;cnt++;
				}
			}
		}
	}cout<<cnt;
	}else{
		cout<<one_being;	
	}
	}
	return 0;
}