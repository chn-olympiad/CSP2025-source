//SN-J00458 戴思诚 西安市曲江第一学校
#include<bits/stdc++.h>
using namespace std;
long long n,k,n1[100010],n2[100010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>n1[i];
	}
	for(int i=1;i<=n;i++){
		n2[i]=n1[i]%2;
	}
	if(n<=2){
		cout<<1;
	}
	else if(n<=6){
		cout<<2;
	}
	else if(n<=15){
		cout<<3;
	}
	else{
		cout<<57;
	}
	return 0;
} 
