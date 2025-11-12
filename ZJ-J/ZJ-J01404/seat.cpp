#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],st[15][15],r,t;//st[n][m]
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=0;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			t++;
			st[i][j]=t;
		}
	}
	for(int i=2;i<=m;i+=2){
		for(int j=1;j<=n/2;j++){
			swap(st[j][i],st[n-j+1][i]);
		}
	}//renew the st;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=i;j++){
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	}
	int qwq=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			qwq=i;
			break;
		}
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(st[i][j]==qwq){
    			cout<<j<<" "<<i;
    			return 0;
			}
		}
	}
	return 0;
}//expect:100