#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	int n,m,k;
	int d[1001];
	cin >> n;
	m=n;
	for(int i=1;i<=m;i++){
		cin>>d[i+1];
		if(d[i+1]!=1&&d[i]!=2&&d[i]!=3&&d[i]!=4&&d[i]!=5&&d[i]!=6&&d[i]!=7&&d[i]!=8&&d[i]!=9){
			d[i+1]= 0;
		}
		if(n!=1&&n!=2&&n!=3&&n!=4&&d[i]!=5&&n!=6&&n!=7&&n!=8&&n!=9){
			n=0;
		}
	}
	for(int i=1;i<m;i++){
		int k=0;
		if(d[i+1]!=0){
			if(d[i+2]>d[i+1]){
				d[i+1]=k;
				d[i+1]=d[i+2];
				d[i+2]=k;
			}
		}
	}				
	if(n!=0){
		cout << n;
	}
	for(int i=1;i<=m;i++){
		if(d[i]!=0){
			cout << d[i+1]; 
		}			
	}
	
	return 0;
}
