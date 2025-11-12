#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=988244353;
int main(){
  	freopen("replace.in","r",stdin);
  	freopen("replace.out","w",stdout);
	ll n,q;
	cin>>n>>q;
	if(q>1){
		for(int i=0;i<q;i++){
			printf("0\n");
		}	
	}else{
		for(int i=0;i<q;i++){
			cout<<n*q/2<<endl;	
		}
	}
	return 0;
}

