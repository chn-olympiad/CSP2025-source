#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int b[n];
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int r,l=0;
	for(int i=1;i<n;i++){
		if(b[i]==k){
			l++;
		}
		if(b[i]==b[i-1]){
			r=0;
		}else{
			r=1;
		}
		if(r==k){
			l++;
		}
	}
	cout<<l;
	return 0;
}
