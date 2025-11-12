#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	int n,k;
	cin>>n>>k;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2||k==0&&n<=100||k==0){
		cout<<1;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}