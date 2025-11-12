#include<bits/stdc++.h>
using namespace std;
int n,m,a[109],s[19][19],R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		k++;
	}
	R=a[1];
	int x;
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(j!=n*m){
				if(a[j]>a[j+1]){
		    		x=a[j];
		    		a[j]=a[j+1];
		    		a[j+1]=x;
				}
			}	    
	    }
	}
    for(int j=1;j<=m;j++){
		for(int z=1;z<=n;z++){
			if(k>=1){
				s[z][j]=a[k+1];
				k--;
			}

		}
	}
	for(int j=1;j<=m;j++){
		for(int z=1;z<=n;z++){
			if(s[z][j]==R){
				cout<<z<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
