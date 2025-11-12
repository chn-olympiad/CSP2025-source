#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	long long n,k,m=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=0;i<n;i++){
			if(a[i]==0){
				m++;
			}
			else{
				if(a[i]==1 and a[i+1]==1){
					m++;
					i++;
				}
			}
		}
	} 
	else{
		for(int i=0;i<n;i++){
			if(a[i]==1){
				m++;
			}
		}
	}
	cout<<m;
	return 0;
} 
