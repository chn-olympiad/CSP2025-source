//吕昊霖-SN-J00182-西安市曲江第二中学 
#include<bits/stdc++.h>
using namespace std;
int a[11*11],b[11*11],p[15][15];
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m,x=b[1];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int f=1;
	sort(b+1,b+n+1);
	for(int i=1;i<=n*m;i++){
		a[i]=b[n*m-i+1];
	}
	for(int i=1;i<=n*m;i++){
		if(i%m==0){
			f=i/m;
			if(f%2==0){
				p[f][1]=a[i];
			}
			else{
				p[f][n]=a[i];
			}
		}
		else if(i%m!=0){
			if(f%2==0){
				p[n-i%m+1][f]=a[i];
			}
			else{
				p[i%m][f]=a[i];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(p[i][j]==x){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
