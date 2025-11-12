#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[105],x,c;
bool V(int b,int a){
	return b>a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	x=b[1];
	sort(b+1,b+n*m+1,V);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=b[++c];
				//cout<<i<<' '<<j<<' '<<a[j][i]<<' ';
			}
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=b[++c];
				//cout<<i<<' '<<j<<' '<<a[j][i]<<' ';
			}
		}
		//cout<<endl;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==x){
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}