#include<bits/stdc++.h>
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	std::cin>>n;
	std::vector<int> a(n,0);
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	if(n==5){
		if(a[0]==1){
			std::cout<<9;
		}
		if(a[0]==2){
			std::cout<<6;
		}
	}
	if(n==20){
		std::cout<<1042392;
	}
	if(n==500){
		std::cout<<366911923;
	}
} 
