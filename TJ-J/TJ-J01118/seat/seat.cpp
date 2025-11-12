#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	int a[110];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}k=a[1];
	int f=1;
	sort(a+1,a+n*m+1,cmp);
	int st[15][15]={};
	int odd=0;
	for(int j=1;j<=m;j++){
		if(odd==0) st[1][j]=st[1][j-1]+1;
		else st[1][j]=j*n;
		odd=1-odd;
	}for(int j=1;j<=m;j++){
		for(int i=2;i<=n;i++){
			if(odd==0) st[i][j]=st[i-1][j]+1;
			else st[i][j]=st[i-1][j]-1;
		}odd=1-odd;
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[st[i][j]]==k){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}return 0;
}
