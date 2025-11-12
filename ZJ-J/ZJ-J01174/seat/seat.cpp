#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int b[11][11];
int cnt=0;
int k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    k=a[1];
    sort(a+1,a+1+m*n,cmp);
    for(int i=1;i<=m;i++){
    	int j;
    	if(i%2==1){
    		for(j=1;j<=m;j++){
    			if(a[++cnt]==k){
    				cout<<i<<' '<<j;
    				return 0;
				}
			}
		}else{
			for(j=m;j>=1;j--){
				if(a[++cnt]==k){
    				cout<<i<<' '<<j;
    				return 0;
				}
			}
    	}
	}
    return 0;
}


