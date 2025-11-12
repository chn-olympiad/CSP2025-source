#include <bits/stdc++.h>
using namespace std;

int a[11][11];
int c[105];
int n,m,R,f;

int main(){
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>c[i];
	}
	R=c[0];
	
	sort(c,c+(n*m));
	
	f=n*m;
	f--;
	int i=1;
	for(;;){
		for(int j=1;j<=n;j++){
			a[i][j]=c[f];
			if(c[f]==R){
				cout<<i<<' '<<j;
				return 0;
			}
			f--;
		}
		i++;
		for(int j=n;j>0;j--){
			a[i][j]=c[f];
			if(c[f]==R){
				cout<<i<<' '<<j;
				return 0;
			}
			f--;
		}
		i++;
	}
	return 0;
}
