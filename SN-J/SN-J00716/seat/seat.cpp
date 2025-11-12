#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,w=0;
	int n2,m2;
	char a[1000001]={};
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		a[1]==k;
		if(a[i]>k){
			w++;
		}
	}
	if(w/n>1){
		m2=w/n;
	}else{
		m2=1;
	} 
	n2=(w+1)%n;
	cout<<m2<<" "<<n2;
	return 0;
	fclose(stdin);
	fclose(stdout); 
}

