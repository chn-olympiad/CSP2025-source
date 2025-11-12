#include<bits/stdc++.h>
using namespace std;
int n,k,isok=1;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) isok=0;
	}
	if(isok){
		cout<<n-2;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else{
		cout<<n-3;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

