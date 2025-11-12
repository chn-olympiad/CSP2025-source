#include"bits/stdc++.h"
using namespace std;
int n,m,a[110],v,ans,c=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	v=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				if(a[c++]==v){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[c++]==v){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
