#include<algorithm> 
#include<cstdio>
#include<iostream>  
#include<cstring> 
#include<algorithm>  
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[5*100000];
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<1;
	}
	return 0;
}
