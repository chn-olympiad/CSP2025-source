#include<bits/stdc++.h>
using namespace std;
int a[21][21];
int n,m,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m; 
    for(int i=1;i<=n;i++){
    	for(int i=1;i<=m;i++){
    	    cin>>a[n][m];
		} 
	}
    	    if(a[1][1]==max(a[n][m],a[n+1][m+1])){
    	    	cout<<"1"<<" "<<"1";
			}
    	cout<<n<<" "<<m;
	
	return 0;
} 
