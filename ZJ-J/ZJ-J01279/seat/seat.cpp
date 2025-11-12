#include<bits/stdc++.h>
using namespace std;
int n,m,s[20][20],a[105],fs;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	fs=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==1) s[i][j]=a[(i-1)*n+j];
			else s[i][n-j+1]=a[(i-1)*n+j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==fs){
				cout<<i<<' '<<j;
				break;
			}
		}
	}
	return 0;
}

