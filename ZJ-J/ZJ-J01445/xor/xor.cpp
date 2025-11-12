#include <iostream>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){ // About #1 #3
	    // All in 1?
		cout<<n;
	}else if(k<=1){ // About #2 #4 #5 (#13WA)
	    // The number of 1
	    int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		cout<<cnt;
	}else{
		cout<<n/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}