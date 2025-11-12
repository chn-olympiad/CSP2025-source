#include<bits/stdc++.h>
using namespace std;
int n,m,b[110],c=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];

	}
	int d=b[1];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<i;j++){
			if(b[i]<b[j]) swap(b[i],b[j]);

		}}
	int e;
	for(int i=0;i<m*n;i++){
		if(b[i]==d){
			e=(i-1)/n+1;

			if(e/2==0)
			cout<<n-(i-1)%n+2;
			else
			cout<<(i-1)%n+1<<" ";
			cout<<e;
	}

	return 0;
}}