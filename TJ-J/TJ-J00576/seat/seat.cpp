#include<bits/stdc++.h>
using namespace std;
int n,m,a,b[102],d[12][12];
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	a=b[0];
	sort(b,b+n*m-1);
	for(int i=0;i<n*m;i++){
		if(b[i]==a){
			a=i+1;
			break;
		}
	}
	cout<<a; 
	for(int i=0;i<n;i++){
		if(!i%2){
			for(int j=0;j<m;j++){
				if(i*m+j+1==a){
					cout<<i+1<<' '<<j+1;
					return 0;
				}
			}	
		}
		else{
			for(int j=m-1;j>=0;j--){
				if(i*m+m-j==a){
					cout<<i+1<<' '<<m-j-1;
					return 0;
				}
			}
		}
	}
	return 0;
}
