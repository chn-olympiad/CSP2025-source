#include<bits/stdc++.h> 
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,z,b[101],f=0,x=0;
	cin>>n>>m;
	for(int j=1;j<=m*n;j++){
		cin>>b[j];
	}
	z=b[1];
	sort(b+1,b+m*n+1);
	for(int j=1;j<=m*n;j++){
		if(b[j]==z){
			z=j;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n&&x!=1;j++){
		    f++;
		    if(f==z&&i%2==1){
		    	cout<<j<<" "<<i;
		    	x=1;
			}
			if(f==z&&i%2==0){
		    	cout<<n-j<<" "<<i;
		    	x=1;
			}
		}
		
	}
	//fclose("seat.in");
	//fclose("seat.out");
	return 0;
}
