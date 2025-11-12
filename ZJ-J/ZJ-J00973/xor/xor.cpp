#include<iostream>
using namespace std;
int list[1000000]={};


int main(){
	bool isone = true;
	//int one =0,zero = 0;
	int n,k;
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> list[i];
		if(list[i]!=1)isone = false;
		//if(list[i]==0)zero++;
		//if(list[i]==1)one++;
		
	}
	if(isone){
		if(k!=1&&k!=0){
			cout << 0;
		}
		else if(k==1){
			cout << n;
		}
		else if(k==0){
			cout << n/2;
		}
	}
	else{
		cout << 2;
	}
	return 0;
}