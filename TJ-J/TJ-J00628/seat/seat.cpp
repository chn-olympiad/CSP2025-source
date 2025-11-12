#include<bits/stdc++.h> 
#include<iostream> 
#include<string> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,z,m,h;
	cin>>a>>b>>z;
	int c=a*b;
	int n[c];
	for(int i=1;i<=c-1;i++){
		cin>>n[i];
	}for(int i=1;i<=c-1;i++){
		for(int j=i;j<=c-1;j++){
			if(n[i]<n[j]){
				int k=n[i];
				n[i]=n[j];
				n[j]=k;
			}
		}
	}for(int i=1;i<=c-1;i++){
		if(z>n[i]){
			m=i;
		    break;
		}
	}int l=m/b;
	if(l==0 || m>l*b){
		l++;
	}
	if(l%2==0){
		h=b-m+(l-1)*b+1;
	}else{
		h=m-(l-1)*b;
	}cout<<l<<" "<<h;
	
	return 0;
}
