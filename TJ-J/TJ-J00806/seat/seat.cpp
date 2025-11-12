#include<bits/stdc++.h>
using namespace std;
int n,m,g,a[105],p,e[15][15];
bool cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	g=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==g){
			p=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		e[i][1]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(j%2==0){
				e[i][j]=e[i][j-1]+(n-i)*2+1;
			}
			else {
				e[i][j]=e[i][j-1]+(i-1)*2+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(e[i][j]==p){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
