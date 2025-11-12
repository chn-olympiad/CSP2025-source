#include<bits/stdc++.h>
using namespace std;
int n,m,num=0;
int a[105];
int s[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){ 
		if(j%2!=0){
		for(int i=1;i<=n;i++){
			s[i][j]=a[++num];
			}
		}
		if(j%2==0){
		for(int i=n;i>=1;i--){
			s[i][j]=a[++num];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==a1)cout<<j<<" "<<i;
		}
	}
	return 0;
}

