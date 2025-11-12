#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,sum=0;
	cin>>a;
	for(int i=0;i<=9;i++){
	
		if(a%10==i&&a%100==i&&a%1000==i&&a%10000==i&&a%100000==i&&a%1000000&&a%10000000==i&&a%100000000==i&&a%1000000000==i&&a%10000000000==i){
			
			sum+=i;
			cout<<sum;
		
			
			
		}
		
		
	}
	
	return 0;
}


