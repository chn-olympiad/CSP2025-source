#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],i,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int j=0;j<n;j++){
		cin>>a[j];
	}
	if(k==0){
		i=1;
		for(int j=0;j<n;j++){
			if(a[i]==0){
				sum++;
			}
			
		}
	}
	for(int j=0;j<i;j++){
		for(int j=i;j<n;j++){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
