#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m;
int a[110],b[15][15];
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int w=a[1];
	sort(a+1,a+n*m+1,cmp);
	int q=1;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				b[i][j]=a[q];
				q++;
			}
		}else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[q];
				q++;
			}
		}

	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==w){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
