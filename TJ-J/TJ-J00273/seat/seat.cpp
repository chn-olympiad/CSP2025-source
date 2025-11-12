#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[100][100],d=0,r=0,w=0;
	cin>>n>>m;
	for(int c=0;c<n;c++){
		for(int b=0;b<m;b++){
			cin>>a[c][b];
		}
	}
	for(int c=0;c<n;c++){
		for(int b=0;b<m;b++){
			if(a[0][0]<a[c][b]){
				d++;
			}
		}
	}
	for(int c=0;c<d;c++){
		
			if(c==n){
				c-n;
				d-n;
				m++;
			}
			r++;
		
	}
	cout<<r<<" "<<m;
	return 0;
} 
