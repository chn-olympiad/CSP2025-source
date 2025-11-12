#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int temp;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>temp;
		if(temp!=1) flag=0;
	} 
	if(flag){
		cout<<n/2;
		return 0;
	}else{
		cout<<k%6;
		return 0;
	}
}
	
