#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b,c[15][15],x,k;
bool q(int l,int o){
	if(l>o)
	    return l>o;
	
	return l>o;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	b=a[1];
	x=0;
	sort(a+1,a+1+m*n,q);
	/*for(int i=1;i<=n*m;i++){
		cout<<a[i];
		
	}*/
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			c[j][i]=a[j+n*x];
		//	cout<<a[k+n*x]<<"\n";
		}
		x+=2;
	}
	x=1;
	k=1;
	for(int i=2;i<=m;i+=2){
		for(int j=n;j>=1;j--){
			c[j][i]=a[k+n*x];
			
			k++;
		}
		x+=1;
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<c[i][j]<<" ";
		}	cout<<"\n";
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==b){
				cout<<j<<" "<<i; 
			}
		}	
	}
	return 0;
} 
