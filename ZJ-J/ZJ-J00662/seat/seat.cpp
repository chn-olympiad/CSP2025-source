#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int n,m;
	int a[110];
	int b[11][11];
	cin>>n>>m;
	cin>>a[1];
	int p=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int k=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[i][j]=a[k];
				k++;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				b[i][j]=a[k];
				k++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==p){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}

