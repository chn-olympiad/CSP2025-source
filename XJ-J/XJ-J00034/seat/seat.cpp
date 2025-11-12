#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z=0;
	cin>>n>>m;
	int a[n*m],b[n][m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0){
			z=a[i];
		}
	}
	sort(a,a+n*m);
	int f=0,s=n*m-1;
	for(int j=0;j<m;j++){
		if(f==0){
			for(int i=0;i<n;i++){
				b[i][j]=a[s];
				s--;
			}
			f=1;
		}
		else{
			for(int i=n-1;i>=0;i--){
				b[i][j]=a[s];
				s--;
			}
			f=0;
		}
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(b[i][j]==z){
				cout<<j+1<<' '<<i+1;
			}
		}
	}
	return 0;
}
