#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[100],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<(n*m);i++){
		cin>>p[i];
	}
	r=p[0];
	sort(p,p+(n*m),greater<int>());
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				if(p[(i*n)+j]==r){
					cout<<i+1<<' '<<j+1;
					return 0;
				}
			}
		}else{
			for(int j=n-1;j>=0;j--){
				if(p[((i+1)*n)-j-1]==r){
					cout<<i+1<<' '<<j+1;
					return 0;
				}
			}
		}
	}
}
