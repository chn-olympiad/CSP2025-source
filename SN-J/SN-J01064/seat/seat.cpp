#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int m,n,a[105],xm,b[15][15],ans=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xm=a[1];
	sort(a+1,a+m*n+1,cmp);
	
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				ans++;
				if(a[ans]==xm){
					cout<<i<<' '<<j;
					break;
				}
				
			}
		}
		else{
			for(int j=m;j>=1;j--){
				ans++;
				if(a[ans]==xm){
					cout<<i<<' '<<j;
					break;
				}
			}
		}
	}
	return 0;
}
