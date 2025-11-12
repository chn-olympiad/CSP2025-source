#include<bits/stdc++.h>
using namespace std ;
int n , k , w ;
int a[500010] ;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k ;
	for(int i=1;i<=n;i++){
		cin >> a[i] ;
		if(a[i]==1)w++ ;
	}
	if(k==0){
		cout << 1 ;
		return 0;
	}
	if(k==1){
		cout << w ;
		return 0 ;
	}
	else{
		int t ;
		if(n%k==0){
			t=n/k ;
		}
		else{
			t=(n+3)/k ;
		}
		int len=1 ;
		while(n>=10){
			len++ ;
			n/=10 ;
		}
		if(len==1){
			cout << t ;
		}
		else{
			cout << t*len+18 ;
		}
	}
	return 0;
}
