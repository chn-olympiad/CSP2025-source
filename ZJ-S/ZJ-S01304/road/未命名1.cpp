#include<bits/stdc++.h>
using namespace std;
int ispr(int x){
	if(x<2)return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;
}
int main(){
	for(int i=1e9;i>=1e9-5000;i--){
		if(ispr(i))cout<<i<<"\n";
	}
}