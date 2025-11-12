#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i+=2){
			if(a[i]==a[i+1]||a[i]==0){
				c++;
			}
			if(a[i+1]==0){
				c++;
			}
		} 
		cout<<c;
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				c++;
			}
		}
		cout<<c;
	}
	else{
		int m=0;
		for(int i=1;i<=n;i++){
			m=(m^a[i]);
			if(m==k){
				c++;
				m=0;
			}
		}
		cout<<c;
	}
	return 0;
} 

