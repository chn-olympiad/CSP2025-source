#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10000];
	for(int i=1;i<= n*m;i++){
		cin>>a[i];
	}
	int count=a[1];
	sort(a,a+ n*m);
	int b[10000][10000];
	int x=1;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				b[i][j]=a[x];
				x++;
			}
		}
		else{
			for(int j=1;j<=m;j++){
				b[i][j]=a[x];
				x++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==count) cout<<i<<","<<j;
		}
	}
	return 0;

}