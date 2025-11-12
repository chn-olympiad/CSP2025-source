#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot,now;
int a[105];
int mp[15][15];
int bh[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			tot++;
			cin>>a[tot];
		}
	}
	k=a[1];
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--){
		now++;
		if(a[i]==k) break;
	}
	int x=1;
	int y=1;
	int flag=1;
	int t=1;
	while(y<=m){
		mp[x][y]=t;
		x+=flag;
		if(x>n){
			x=n;
			y++;
			flag=-1;
		}
		if(x==0){
			x=1;
			flag=1;
			y++;
		}
		t++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==now){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}