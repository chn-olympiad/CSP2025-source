#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[105][105],c[10086],l,v,b,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		l=c[1];
		cin>>c[i];
	}
	v=m*n;
	b=n;
	sort(c+1,c+1+m*n);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]==c[v];
				if(c[v]==l){
					cout<<i<<" "<<j;
					return 0;
				}
				v--;
			} 
		} 
		else{
			for(int j=n;j>=1;j--){
				a[i][j]==c[v];
				if(c[v]==l){
					cout<<i<<" "<<j;
					return 0;
				}
				v--;
			}
		}
	}
}
