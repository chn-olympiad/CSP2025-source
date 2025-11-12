#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c[10000],d[100][100],ming,l=1,e[10000],z=1;
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
			cin>>c[i];
	}
		
	ming=c[1];
	sort(c,c+a);
	for(int i=a*b;i>=1;i--){
		e[l]=c[i];
		l=l+1;
	}
	for(int i=1;i<=b;i++){	
		if(i%2==0){
		for(int j=a;j>=1;j--){
			d[i][j]=e[z];
			z=z+1;
			if(d[i][j]==ming){
				cout<<i<<' '<<j;
			}
		}
		
		
		}
		else{
		
		for(int j=1;j<=a;j++){
			d[i][j]=e[z];
			z=z+1;	
			if(d[i][j]==ming){
				cout<<i<<' '<<j;
			}
		}
		}
}	
}
	


         






