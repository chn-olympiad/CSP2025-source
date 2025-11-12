#include<bits/stdc++.h>
using namespace std;
int s[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=0,e=100,c,r;
	cin>>n>>m;
	int b[n*m];
	for(int i=1;i<=m*n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=m;i++){
	    if(i%2==0){
	    	for(int j=n;j>=1;j--){
				if(b[1]==e){
					c=i;
					r=n;
				}
				e--;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(b[1]==e){
					c=i;
					r=j;
				}
				e--;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
