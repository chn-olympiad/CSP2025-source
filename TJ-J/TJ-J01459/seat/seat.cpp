#include<bits/stdc++.h>
using namespace std;
int n,m,a1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int arr[n][m],a[n*m];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    a1=a[0];
	}
	sort(a,a+n*m);

	for(int i=1;i<=n;i++){
	    if(i%2==0){
	    	for(int j=1;j<=m;j++){
	    		arr[i][j]=a[i-1];
	    		if(a[i-1]=a1){
	    			cout<<i<<" "<<j;
	    			return 0;
				}
			}
		}
		else{
			for(int j=m;j>0;j--){
	    		arr[i][j]=a[i-1];
	    		if(a[i-1]=a1){
	    			cout<<i<<" "<<j;
	    			return 0;
				}
			}
		}
			
	    
	
	}
	return 0;
}
