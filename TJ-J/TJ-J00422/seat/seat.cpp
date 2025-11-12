#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,a[15];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(r==a[i]){
					if(i%n==0){
						k=i/n;
					}else{
						k=i/n+1;
					}
					if(k%2==0){
						j=n-i%(n*(k-1))+1;
					}else{
						j=i-(n*(k-1));
					}
					cout<<k<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

