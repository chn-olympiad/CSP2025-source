#include <bits/stdc++.h>
using namespace std;
int n,m,s0;
int a[110];
int sit[15][15];
int cmp(int x,int y){
	return x>y;
}
int cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	s0=a[0];
	sort(a,a+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				sit[i][j]=a[cnt];
				if(a[cnt]==s0){
					cout<<i<<' '<<j;
					return 0;
				}
				cnt++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				sit[i][j]=a[cnt];
				if(a[cnt]==s0){
					cout<<i<<' '<<j;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}