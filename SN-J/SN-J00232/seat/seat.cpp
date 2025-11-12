#include<bits/stdc++.h>
using namespace std;
int a[121],s[11][11];
int n,b,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[(i-1)*m+j]==b) {
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else if(i%2==0){
			for(int j=1;j<=m;j++){
				if(a[(i-1)*m+m-j+1]==b){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}


