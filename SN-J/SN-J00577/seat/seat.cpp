#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[1005],r;
int y=0;
bool sss(int x,int y){
	return x>y;
}
void paint(int x){
	if(x%2==1){
		for(int i=1;i<=m;i++){
			a[i][x]=b[y];
			y++;
		}
	}else{
		for(int i=m;i>=1;i--){
			a[i][x]=b[y];
			y++;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	r=b[0];
	sort(b+0,b+n*m,sss);
	for(int i=1;i<=n;i++){
		paint(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

