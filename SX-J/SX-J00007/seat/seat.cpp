#include<bits/stdc++.h>
using namespace std;
int n,m,r,s;
int a[1005],ax[1005],b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m; i>=1; i--){
        s++;
        ax[s]=a[i];
    }
    s=0;
    for(int i=1; i<=n; i++){
        if(i%2==1){
            for(int j=1; j<=m; j++){
                s++;
                b[j][i]=ax[s];
            }
        }
        else{
            for(int j=m; j>=1; j--){
                s++;
                b[j][i]=ax[s];
            }
        }
    }
    for(int i=1; i<=n; i++){
    	for(int j=1;j<=m;j++){
			if(b[j][i]==r){
  	            cout<<i<<" "<<j;
            	break;
        	}
		}
    }
    return 0;
}