#include<bits/stdc++.h>
using namespace std;
int a[115];
int n,m;
int tar=0;
bool c(int a,int b){
	return a>b;
}
int fi(int t){
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			return i;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=m*n;j++){
		cin>>a[j];
		if(j==1){
			tar=a[j];
		}
	}
	sort(a+1,a+n*m+1,c);
	int x=fi(tar);
	int p=0;
	for(int j=1;;j++){
		int u;
		if(j%2==1) {
			for(int i=1;i<=n;i++){
				p++;
				if(p==x){
					cout<<j<<' '<<i;
					return 0;
				}	
			}
		}
		else {
			for(int i=n;i>=1;i--){
				p++;
				if(p==x){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		
	}
}
