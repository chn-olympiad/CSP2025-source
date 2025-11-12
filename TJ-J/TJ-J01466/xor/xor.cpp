#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[10008];
int num;//有多少个1 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(long long i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]==1) num++;
	}
	if(k==0){
		cout<<num/2;
	}else if(k==1){
		cout<<num;
	}
	
	
	
	
	
	return 0;
} 
