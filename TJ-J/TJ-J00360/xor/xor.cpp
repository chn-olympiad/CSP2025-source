#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n,k;
    for(int i =1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]==k) sum++;
	} 
	if(k==0){
		cout<<n/2;
		return 0;
	} 
	cout<<sum;
	return 0;
}

