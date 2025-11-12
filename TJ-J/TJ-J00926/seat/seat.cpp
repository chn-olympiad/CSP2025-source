#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[10005],c,d=1,e[35];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>b[i];
	}
	c=b[1];
	sort(b+1,b+n*m+1);
	for(int i=n*m;i>=1;i--){
		e[d]=b[i];
		d++;
	}
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1,p=(j-1)*n+1;i<=n;i++,p++){
				a[i][j]=e[p];
			}
		}else if(j%2==0){
			for(int k=n,o=(j-1)*n+1;k>=1;k--,o++){
				a[k][j]=e[o];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==c){
				cout<<j<<' '<<i;
				break;
			}
		}
		}
		fclose(stdin);
		fclose(stdout);
	return 0;
}
