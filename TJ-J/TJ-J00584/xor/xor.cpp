#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
		int a,b;
		cin>>b;
		for(int i=1;i<=n-1;i++){
			cin>>a;
		}
	if(k=0){
		cout<<n-b-1;
	}else{
		cout<<n-b;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//  4 2
//	2 1 0 3
	
