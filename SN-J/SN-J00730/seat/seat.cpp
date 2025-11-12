#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int map[11][11];
int abc(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,abc);
	int ans=0;
	for(int i=1;i<=n*m;i++){
		ans++;
		if(a[i]==x){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				int h=(i-1)*n+j;
				if(h==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else if(i%2==0){
			int y=0;
			for(int j=m;j>=1;j--){
				y++;
				int h=(i-1)*n+y;
				if(h==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
