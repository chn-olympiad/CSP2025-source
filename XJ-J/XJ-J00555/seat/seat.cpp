#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010][1010],b[100010],y,s,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m*n;i++){
		cin>>b[i];
		ans=b[0];
	}
	for(int i=0;i<m*n;i++){
		if(b[i]<b[i+1]){
			y=b[i];
			b[i]=b[i+1];
			b[i+1]=y;
		}
		
	}
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				a[j][i]=b[s];
				s++;
		    }		
		}else{
			for(int j=m-1;j>=0;j--){
				a[j][i]=b[s];
				s++;
			}		
		}
	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==ans){
				cout<<j+1<<' '<<i+1;
				break;
			}
		}
	}		
	return 0;
}
