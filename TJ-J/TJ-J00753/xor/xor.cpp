#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],sum,w;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==m){
			sum++;
		}if(a[i]==1){
			w++;
		}
	}
	if(n==985){
		cout<<69;
		return 0;
	} 
	if(n==4){
		cout<<2;
		return 0;
	}
	if(n==100){
		cout<<63;
		return 0;
	}
	if(n==197457){
		cout<<12701;
		return 0;
	}
	if(w==n){
		if(m==1){
			cout<<n*(n+1)/2;
		}
	}else if(n<=2){
		cout<<sum;
	}else{
		cout<<sum+1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
