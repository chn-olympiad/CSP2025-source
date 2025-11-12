#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	int l=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i+=1){
		cin>>a[i];
	}
	if(k==0){
		for(int i=0;i<n;i+=1){
			if(a[i]==a[i+1]){
				l+=1;
				i+=1;
			}
		}
	}
	else{
		for(int i=0;i<n;i+=1){
			if(a[i]==1){
				l+=1;
			}
		}
	}
	cout<<l;
	return 0;
}
