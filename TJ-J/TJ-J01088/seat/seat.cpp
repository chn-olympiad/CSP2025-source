#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	int n,m;
	cin>>n>>m;
	int num[n*m +1];
	for(int i=0;i<n*m;i++){
		cin>>num[i];
	}
	
	int fs=num[0];
	
	for(int i=0;i<n*m-1;i++){
		for(int j=0;j<n*m-1;j++){
			if(num[j]<num[j+1]){
				swap(num[j],num[j+1]);
			}
		}
	}
	
	int pm=1;
	for(int i=0;i<n*m;i++){
		if(num[i]==fs){
			break;
		}
		pm++;
	}
	
	
	int m1=pm,n1;
	m1--;
	cout<<m1/n+1;
	
	n1=pm%n;
	if(n1==0) n1=n;
	
	if(m1%2!=0){
		n1=n+1-n;
	}
	
	cout<<" "<<n1;
	
	return 0;
}
