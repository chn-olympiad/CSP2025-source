#include<bits/stdc++.h>
using namespace std;
int a[100010];
int seat[1010][1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				cnt++;
				seat[i][j]=cnt;
			}
		}else{
			for(int i=n;i>=1;i--){
				cnt++;
				seat[i][j]=cnt;
			}
		}
	}
	int p=1;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]){
			p++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
	 	    if(seat[i][j]==p){
	 	    	cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}