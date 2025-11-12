#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,f=1;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	 	cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==0){
				if(a[(i-1)*n+m-j+1]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			else if(i%2==1){
				if(a[(i-1)*n+j]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}