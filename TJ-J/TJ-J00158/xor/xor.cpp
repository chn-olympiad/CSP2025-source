#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],r=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
		return 0;
	}
	for(int j=1;j<=n;j++){
		for(int k=j;k<=n;k++){
			int c=0;
			for(int l=j;l<k;l++){
				c+=a[l]^a[l+1];
			}
			if(c==k) r++; 
		}
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
