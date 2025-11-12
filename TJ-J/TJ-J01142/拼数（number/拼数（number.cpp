#include<bits/stdc++.h>
using namespace std;
int main(){
	int s;
	cin>>s;
	int k = 0;
	int n = 0;
	int m;
	for(int i = s;i>0;i--){
		n = s%100/10;
		k = s%10;
		
	}
	if(k>n){
		if(k==0){
			cout<<n;
			return 0;
		}else if(n==0){
			cout<<k;
			return 0;
		}
		cout<<k<<n;
	}else{
		if(k==0){
			cout<<n;
			return 0;
		}else if(n==0){
			cout<<k;
			return 0;
		}
		cout<<n<<k;
	}
}
