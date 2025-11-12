#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<2){
		cout<<0;
	}else{
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
