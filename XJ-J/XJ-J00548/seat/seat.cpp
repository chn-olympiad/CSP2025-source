#include<bits/stdc++.h>
#include<cstdio>
int n,m,n1,m1,cj[110],r;
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;	
	for(int i=0;i<n*m;i++){
		cin>>cj[i];
	}
	if(n==1&&m==1){
		cout<<"1"<<" "<<"1";
	}
	if(n==1&&m<=10&&m>1){
		for(int i=0;i<m;i++){
			if(cj[0]<cj[i+1]){
				r++;
			}
		}
		cout<<"1"<<" "<<r+1; 
	}
	if(m==1&&n<=10&&n>1){
		for(int i=0;i<n;i++){
			if(cj[0]<cj[i+1]){
				r++;
			}
		}
		cout<<r+1<<" "<<"1"; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
