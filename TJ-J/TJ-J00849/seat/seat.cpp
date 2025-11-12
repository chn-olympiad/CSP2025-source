#include<bits/stdc++.h>
using namespace std;
int a[19][19];
int x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	if(n==1){
		if(n==1&&m==1){
			x=1;
			y=1;
			cout<<x<<" "<<y;
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]<a[i][j+1]){
					swap(a[i][j],a[i][j+1]);
				} 
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<a[i][j];
			}
		}
	}
	
	
	return 0;
}

