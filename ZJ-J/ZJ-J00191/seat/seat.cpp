#include<bits/stdc++.h>
using namespace std;
int m,n,a[110],s[15][15],k,R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//n––m¡– 
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	R=a[0];
	sort(a,a+n*m);
	k=n*m-1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				s[i][j]=a[k];
				k--;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				s[i][j]=a[k];
				k--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]==R){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
	
}
