#include<bits/stdc++.h>
using namespace std;
int s[1000000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,e,g;
	int q;
	cin>>m>>n;
	e=m*n;
	cin>>g;
	s[1]=g;
	for(int i=2;i<=e;i++){
		cin>>s[i];	
	}
	sort(s,s+e+1);
	for(int i=e;i>=1;i--){
		if(s[i]==g){
			q=i;
		}	
	}
	if(q%m>0){
		cout<<q/m+1;
		if((q/m+1)%2==0){
			cout<<q-m/q*n;
		}
		else{
			cout<<m/q*n-q;
		} 
	}
	else{
		cout<<q/m;
		if((q/m+1)%2==0){
			cout<<q-m/q*n;
		}
		else{
			cout<<m/q*n-q;
		} 
	}
	
	return 0;
}

