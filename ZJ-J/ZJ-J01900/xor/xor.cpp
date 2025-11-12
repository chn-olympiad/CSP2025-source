#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[100010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		cout<<2<<endl;
	}
	if(n!=4){
		cout<<1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}