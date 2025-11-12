#include<bits/stdc++.h>
using namespace std;
int a[110],mp[11][11];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				mp[j][i]=a[(i-1)*n+j];
			}	
		}else{
			for(int j=n;j>=1;j--){
				mp[j][i]=a[(i-1)*n+(n-j+1)];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==r){
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}