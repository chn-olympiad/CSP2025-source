#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int c_1=0;
	int c_0=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==1){
			c_1++;
		}
		else if(x==0){
			c_0++;
		}
	}
	if(c_1+c_0==n){
		if(c_0>0){
			if(k==0){
				cout<<c_0;
				return 0;
			}
			else if(k==1){
				cout<<c_1;
				return 0;
			}
		}
		else{
			if(k==0){
				cout<<n/2;
				return 0;
			}
			else if(k==1){
				cout<<c_1;
				return 0;
			}
		}
	}
	return 0;
}
