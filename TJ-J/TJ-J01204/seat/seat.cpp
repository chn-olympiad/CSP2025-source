#include <bits/stdc++.h>
using namespace std;
int a[15][15],b[110],c[15][15];
int main(){
	freopen("seat.in","r",std.in);
	freopen("seat.out","w",std.out);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}else{
			for(int j=n;j>=1;j--){
				cin>>a[i][j];
			}
		}
	}
	int d=a[1][1];
	int s=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			b[s]=a[i][j];
			s++;
		}
	}
	for(int i=1;i<=s;i++){
		for(int j=i+1;j<=s;j++){
			if(b[i]<b[j]){
				swap(b[i],b[j]);
			}
		}
	}
	int x=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				c[i][j]=b[x];
				x++;
				if(c[i][j]==d){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				c[i][j]=b[x];
				x++;
				if(c[i][j]==d){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
}
