#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,x,a[110],b[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	a[n*m]=x;
	sort(a+1,a+1+n*m);
	
	int i=n*m;
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int k=1;k<=n;k++){
				
				b[j][k]=a[i];
				
				if(a[i]==x){
					c=j;
					r=k;
				}
				i--;
				if(i<=0)break;
			}
		}
		else{
			for(int k=n;k>=1;k--){
				b[j][k]=a[i];
				
				
				if(a[i]==x){
					c=j;
					r=k;
				}
				i--;
				if(i<=0)break;
				
			}
		}
		if(i<=0)break;
	}
	
	cout<<c<<" "<<r;
	return 0;
}
