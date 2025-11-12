#include<bits/stdc++.h>
using namespace std;
int main (){
	
	//preopen("xor.in","r",stdin)
	//preopen("xor.out,"w",stdout)
	
	int l,r,n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>l>>r;
		if(l=r){
			cout<<"1"<<endl;
		}
		else{
			cout<<"0"<<endl;
		}
	}
	return 0;
}
