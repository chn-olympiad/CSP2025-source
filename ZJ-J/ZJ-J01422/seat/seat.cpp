#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],f,b[15][15];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;){
		for(int j=1;j<=m;j++){
			if(j%2==0){
				for(int k=n;k>=1;k--){
					b[j][k]=a[i];
					i++;
				}
			}else{
				for(int k=1;k<=n;k++){
					b[j][k]=a[i];
					i++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==f){
				cout<<i<<" "<<j<<"\n";
				return 0;
			}
		}
	}
	return 0;
}

