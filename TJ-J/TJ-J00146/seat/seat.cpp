#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q=0; 
	cin>>n>>m;
	int a[n*m],b=1,c=1,h;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int e=a[0];
	for(int i=0;i<n;i++){
		if(a[i]>q){
			q=a[i];
			if(q==a[0]){
				b=h;
			}
		}
		h=i;		
	} 
	if(e==q){
		cout << b << c;	
	}
	return 0;
} 
