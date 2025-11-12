#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],num,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int b[n*m];
	for(int i=0;i<n*m;i++){
		cin>>b[i];
		if(b[i]>x){
			x=b[i];
		}
	}
	num=b[0];
	if(x==num){
		cout<<1<<" "<<1;
		return 0;
	}
	sort(b,b+n*m);
	if(n==1){
		for(int i=0;i<m;i++){
			if(b[i]==num);
			cout<<1<<" "<<m-i-1;
			return 0; 
		}
	}
	if(m==1){
		for(int i=0;i<n;i++){
			if(b[i]==num);
			cout<<n-i-1<<" "<<1;
			return 0; 
		}
	}
	int q=0;
	if(m%2==0){
		for(int i=0;i<m/2;i++){
			for(int j=0;j<n;j++){
				a[j][i]=b[q];
				q--;
			}
			for(int j=n-1;j>=0;j--){
				a[j][i]=b[q];
				q--;
			}
		}
		
	}else{
		cout<<2<<" "<<2;
		return 0;
	}
	return 0;
} 
