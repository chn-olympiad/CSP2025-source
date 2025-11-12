#include<bits/stdc++.h> 
using namespace std;
int n,m,b[101];
int a[11][11];
int pm=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int s=b[1];
	for(int i=0;i<=n*m;i++){
		if(b[i]>s){
			pm++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=i,j;
		}
		i++;
		for(int j=m;j>0;j--){
			a[i][j]=i,j;
		}
	}
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=m;j++){
			cout<<a[i][j];
		}
	}
	return 0;
}
